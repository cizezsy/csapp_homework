#include<stdio.h>

int generateWord(int x, int y);

int main() {
  printf("%x", generateWord(0x89ABCDEF, 0x76543210));
  return 0;
}

int generateWord(int x, int y) {
  x = ((1 << 8) - 1) & x;
  y = (y >> 8) << 8;
  return x | y;
}
