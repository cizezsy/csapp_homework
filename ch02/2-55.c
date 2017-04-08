#include<stdio.h>

typedef unsigned char *byte_ptr;

void show_bytes(byte_ptr byteptr, int length);

int main() {
  int a = 256;
  show_bytes((byte_ptr)&a, 9);
  return 0;
}

void show_bytes(byte_ptr byteptr, int length) {
  for(int i = 0; i < length; ++i) {
    printf("%.2x ", *(byteptr+i));
  }
}
