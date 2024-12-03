# Derleyici
CC = gcc

# Derleme seçenekleri
CFLAGS = -Wall -Wextra -O2

# Kaynak dosyaların bulunduğu dizin (ana dizin)
SRCDIR = main.c

# Tüm kaynak dosyaları (*.c)
SRCS = $(wildcard $(SRCDIR)/*.c)

# Nesne dosyaları (*.o)
OBJS = $(SRCS:.c=.o)

# Çıktı dosyası (program adı)
TARGET = program

# Varsayılan hedef
all: $(TARGET)

# Programı oluştur
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# .c dosyalarını .o dosyalarına çevir
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Temizleme komutu
clean:
	rm -f $(OBJS) $(TARGET)
