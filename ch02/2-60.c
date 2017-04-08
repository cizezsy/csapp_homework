#include<stdio.h>

typedef char *byte_ptr;

unsigned replace_byte (unsigned x, int i, unsigned char b);

int main() {
  printf("%x", replace_byte(0x12345678, 0, 0xAB));
  return 0;
}

unsigned replace_byte (unsigned x, int i, unsigned char b) {
  unsigned t = x;
  byte_ptr t_ptr =(byte_ptr)&t;
  *(t_ptr+i) = b;
  return t;
}
