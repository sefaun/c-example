#include <stdio.h>

extern int sharedData;

int main() {

  printf("%d\n", sharedData);

  return 0;
}