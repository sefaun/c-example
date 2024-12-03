#include <stdio.h>

int main()
{
  // 1
  // unsigned char a = 0b1101; // 13
  // unsigned char b = 0b1011; // 11

  // unsigned char sum = a + b;
  // printf("%#04x + %#04x = %#04x (%d)\n", a, b, sum, sum);

  // 2
  // unsigned char a = 0b1101; // 13

  // unsigned char not_result = ~a;
  // printf("NOT %#04x = %#04x (%d)\n", a, not_result, not_result);

  // 3
  // unsigned char a = 0b1101; // 13
  // unsigned char b = 0b1011; // 11

  // unsigned char xor_result = a ^ b;
  // printf("%#04x XOR %#04x = %#04x (%d)\n", a, b, xor_result, xor_result);

  // 4
  // unsigned char a = 0b1101; // 13
  // unsigned char b = 0b1011; // 11

  // unsigned char or_result = a | b;
  // printf("%#04x OR %#04x = %#04x (%d)\n", a, b, or_result, or_result);

  // 5
  char a = 0x0d; // 13
  char b = 0b00001011; // 11

  char and_result = a & b;
  printf("%#04x AND %#04x = %#04x (%d)\n", a, b, and_result, and_result);

  return 0;
}
