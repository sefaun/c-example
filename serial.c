#include <windows.h>
#include <stdio.h>

int main()
{
  HANDLE hSerial;              // Seri port tanımlayıcı
  DCB dcbSerialParams = {0};   // Seri port yapılandırması için yapı
  COMMTIMEOUTS timeouts = {0}; // Zaman aşımı yapılandırması

  // Seri portu aç
  hSerial = CreateFile(
      "\\\\.\\COM10",               // COM port ismi (örn: COM10)
      GENERIC_READ | GENERIC_WRITE, // Okuma ve yazma erişimi
      0,                            // Paylaşım yok
      NULL,                         // Varsayılan güvenlik
      OPEN_EXISTING,                // Mevcut cihazı aç
      0,                            // Varsayılan özellikler
      NULL                          // Şablon yok
  );

  if (hSerial == INVALID_HANDLE_VALUE)
  {
    printf("Seri port açılamadı. Hata: %ld\n", GetLastError());
    return 1;
  }

  printf("Seri port açıldı.\n");

  // Seri port parametrelerini ayarla
  dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
  if (!GetCommState(hSerial, &dcbSerialParams))
  {
    printf("Seri port durumu alınamadı.\n");
    CloseHandle(hSerial);
    return 1;
  }

  dcbSerialParams.BaudRate = CBR_9600;   // Baud hızı: 9600
  dcbSerialParams.ByteSize = 8;          // Veri bitleri: 8
  dcbSerialParams.StopBits = ONESTOPBIT; // Stop bit: 1
  dcbSerialParams.Parity = NOPARITY;     // Parite: Yok

  if (!SetCommState(hSerial, &dcbSerialParams))
  {
    printf("Seri port yapılandırılamadı.\n");
    CloseHandle(hSerial);
    return 1;
  }

  // Zaman aşımı parametrelerini ayarla
  timeouts.ReadIntervalTimeout = 50;         // Maksimum okuma aralığı (ms)
  timeouts.ReadTotalTimeoutConstant = 50;    // Sabit okuma zamanı (ms)
  timeouts.ReadTotalTimeoutMultiplier = 10;  // Okuma çarpanı
  timeouts.WriteTotalTimeoutConstant = 50;   // Sabit yazma zamanı (ms)
  timeouts.WriteTotalTimeoutMultiplier = 10; // Yazma çarpanı

  if (!SetCommTimeouts(hSerial, &timeouts))
  {
    printf("Zaman aşımı ayarlanamadı.\n");
    CloseHandle(hSerial);
    return 1;
  }

  // Veri gönder
  char sendData[100];
  printf("Bir isim girin: ");
  fgets(sendData, sizeof(sendData), stdin);
  printf("girilen veri: %s\n", sendData);
  printf("girilen veri uzunluğu: %d\n", strlen(sendData));

  DWORD bytesWritten;
  if (!WriteFile(hSerial, sendData, strlen(sendData), &bytesWritten, NULL))
  {
    printf("Veri gönderilemedi.\n");
    CloseHandle(hSerial);
    return 1;
  }
  printf("Gönderilen veri: %s\n", sendData);

  // Yanıt oku
  char buffer[1];
  DWORD bytesRead;
  if (ReadFile(hSerial, buffer, sizeof(buffer) - 1, &bytesRead, NULL))
  {
    buffer[bytesRead] = '\0'; // Null-terminator ekle
    printf("Alınan veri: %s\n", buffer);
  }
  else
  {
    printf("Veri okunamadı.\n");
  }

  // Seri portu kapat
  CloseHandle(hSerial);
  printf("Seri port kapatıldı.\n");

  return 0;
}