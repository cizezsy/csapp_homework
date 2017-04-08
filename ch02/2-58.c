#include<stdio.h>

typedef char *byte_ptr;

int is_little_endian();

int main() {
  printf("%d", is_little_endian());
  return 0;
}

int is_little_endian() {
  int foo = 1;
  return *((byte_ptr)&foo) == foo;
}
