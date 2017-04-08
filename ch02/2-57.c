#include<stdio.h>


typedef unsigned char *byte_ptr;

void show_bytes(byte_ptr byteptr, int length);

void show_short(short *s_ptr);

void show_long(long *l_ptr);

void show_double(double *d_ptr);

int main() {
  short s = 123;
  long l = 123;
  double d = 123;
  show_short(&s);
  show_long(&l);
  show_double(&d);
  return 0;
}

void show_short(short *s_ptr) {
  show_bytes((byte_ptr)s_ptr, sizeof(short));
}

void show_long(long *l_ptr) {
  show_bytes((byte_ptr)l_ptr, sizeof(long));
}

void show_double(double *d_ptr) {
  show_bytes((byte_ptr)d_ptr, sizeof(double));
}


void show_bytes(byte_ptr byteptr, int length) {
  for(int i = 0; i < length; ++i) {
    printf("%.2x ", *(byteptr+i));
  }
  printf("\n");
}
