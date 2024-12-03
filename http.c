#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <pthread.h>

// HTTP isteği sonucu dönen veriyi tutmak için bir struct
struct Memory {
    char *data;
    size_t size;
};

// Yazma callback fonksiyonu
size_t write_callback(void *ptr, size_t size, size_t nmemb, struct Memory *mem) {
    size_t new_len = mem->size + size * nmemb;
    mem->data = realloc(mem->data, new_len + 1);
    if (mem->data == NULL) {
        printf("Memory allocation error\n");
        return 0;
    }
    memcpy(mem->data + mem->size, ptr, size * nmemb);
    mem->data[new_len] = '\0';
    mem->size = new_len;
    return size * nmemb;
}

// Asenkron HTTP isteği yapma fonksiyonu
void *http_request(void *url) {
    CURL *curl;
    CURLcode res;
    struct Memory chunk = {0};  // Veriyi tutacak yer

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, (char *)url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);

        // HTTP isteğini başlat
        res = curl_easy_perform(curl);

        // İstek başarılı ise
        if (res == CURLE_OK) {
            printf("HTTP Response: %s\n", chunk.data);
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Temizleme
        free(chunk.data);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Asenkron iki HTTP isteği başlat
    pthread_create(&thread1, NULL, http_request, "https://jsonplaceholder.typicode.com/posts/1");
    pthread_create(&thread2, NULL, http_request, "https://jsonplaceholder.typicode.com/posts/2");

    // İsteklerin bitmesini bekle
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
