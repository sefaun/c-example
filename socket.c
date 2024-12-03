//Derle -> gcc ./socket.c -lws2_32 -o socket.exe
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <string.h>

#define PORT 1453
int main()
{
  WSADATA wsaData;
  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
  {
    fprintf(stderr, "WSAStartup başarısız.");
    return 1;
  }

  int yol = socket(AF_INET, SOCK_STREAM, 0);
  if (yol == INVALID_SOCKET)
  {
    fprintf(stderr, "Socket oluşturulamadı.");
    WSACleanup();
    return 1;
  }

  struct sockaddr_in sunucu_bilgileri;
  memset(&sunucu_bilgileri, 0, sizeof(sunucu_bilgileri));
  sunucu_bilgileri.sin_family = AF_INET;
  sunucu_bilgileri.sin_addr.s_addr = htonl(INADDR_ANY);
  sunucu_bilgileri.sin_port = htons(PORT);

  if (bind(yol, (struct sockaddr *)&sunucu_bilgileri, sizeof(sunucu_bilgileri)) == SOCKET_ERROR)
  {
    fprintf(stderr, "Bağlama sırasında hata oluştu.");
    closesocket(yol);
    WSACleanup();
    return 1;
  }

  if (listen(yol, 5) == SOCKET_ERROR)
  {
    fprintf(stderr, "Dinleme sırasında hata oluştu.");
    closesocket(yol);
    WSACleanup();
    return 1;
  }

  struct sockaddr_in istemci_bilgileri;
  int boyut = sizeof(istemci_bilgileri);
  int istemci_yol = accept(yol, (struct sockaddr *)&istemci_bilgileri, &boyut);
  if (istemci_yol == INVALID_SOCKET)
  {
    fprintf(stderr, "İsteklerin kabulü sırasında hata oluştu.");
    closesocket(yol);
    WSACleanup();
    return 1;
  }

  const char *mesaj = "Merhaba ben Yusuf Sezer";
  if (send(istemci_yol, mesaj, strlen(mesaj), 0) == SOCKET_ERROR)
  {
    fprintf(stderr, "Mesaj gönderimi sırasında hata oluştu.");
  }

  closesocket(istemci_yol);
  closesocket(yol);
  WSACleanup();

  return 0;
}
