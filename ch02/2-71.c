#include<stdio.h>

typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum);

int main() {
  printf("%x", xbyte(0x64ff1280, 2));
  return 0;
}

int xbyte(packed_t word, int bytenum) {
  return ((int)word << ((3 - bytenum) << 3)) >> (3 << 3);
}
