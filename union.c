#include <stdio.h>
#include <stdint.h>

union GeneralFlags
{
  struct
  {
    uint8_t flag1;
    uint8_t flag2;
    uint8_t flag3;
    uint8_t flag4;
  } flags;
  uint32_t allFlags;
};

uint32_t aa = 70000;

int main()
{
  union GeneralFlags generalFlags;
  generalFlags.allFlags = aa;

  // generalFlags.flags.flag1 = 1;
  // generalFlags.flags.flag2 = 1;

  printf("bayrak 1: %d\n", generalFlags.flags.flag1);
  printf("bayrak 2: %d\n", generalFlags.flags.flag2);
  printf("bayrak 1: %d\n", generalFlags.flags.flag3);
  printf("bayrak 2: %d\n", generalFlags.flags.flag4);
  printf("Sonuc: %d\n", generalFlags.allFlags);

  return 0;
}
