#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
  // 1
  // char *sefa = "1asd asd asd asd asd as dasd as 1";
  // char *set = sefa;
  // int erdem = 10;
  // int *set2 = &erdem;

  // printf("%s\n", set);
  // printf("%d\n", *set2);

  // 2
  // struct Sefa
  // {
  //   char *name;
  //   uint8_t age;
  // };

  // struct Sefa var1;

  // var1.name = "nisa nur";
  // var1.age = 25;

  // printf("%s isimli %d yaşında mısın?\n", var1.name, var1.age);

  // 3
  // struct Sefa
  // {
  //   char *name;
  //   uint8_t age;
  // };

  // struct Sefa var1;
  // struct Sefa var2;
  // struct Sefa var3;
  // var1.name = "isim 1";
  // var1.age = 25;
  // var2.name = "isim 2";
  // var2.age = 26;
  // var3.name = "isim 3";
  // var3.age = 27;

  // struct Sefa allData[] = {
  //     var1,
  //     var2,
  //     var3,
  // };

  // printf("%s isimli %d yaşında mısın?\n", var1.name, var1.age);
  // printf("%s isimli %d yaşında mısın?\n", var2.name, var2.age);
  // printf("%s isimli %d yaşında mısın?\n", var3.name, var3.age);
  // printf("%s isimli %d yaşında mısın?\n", allData[0].name, allData[0].age);

  // 4
  // typedef struct
  // {
  //   char name[100];
  //   int64_t age;
  // } Erdem;

  // typedef struct
  // {
  //   char *name;
  //   uint8_t age;
  //   Erdem erdem;
  // } Sefa;

  // Sefa var1;
  // // char *value = "Erdem";
  // char value[100] = "Erdem";

  // for (int i = 0; i < strlen(value); i++)
  // {
  //   var1.erdem.name[i] = value[i];
  // }

  // var1.erdem.age = 25;
  // printf("%s isimli %d yaşında mısın?\n uzunluk: %d\n", var1.erdem.name, var1.erdem.age, strlen(value));

  // 5
  // char *value = "Erdem";
  // char value1[100];

  // char *result = strcpy(value1, value);
  // printf("sonuc: %s --- sonuc: %p\n", result, &result);
  // printf("deger1: %s --- deger: %s\n uzunluk: %d\n", value1, value, strlen(value1));

  // 6
  unsigned char a = 0xFF;
  unsigned char b = 255;

  printf("%d - %d\n", a, b);

  return 0;
}