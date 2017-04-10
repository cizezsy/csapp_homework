#include<stdio.h>

/*
 * Do rotating left shift 
 */
unsigned rotate_left(unsigned x, int n);

int main() {
  printf("%x", rotate_left(0x12345678, 0));
  return 0;
}

unsigned rotate_left(unsigned x, int n) {
  int w = sizeof(int) << 3;
  unsigned int t = x >> (w - n);
  x = x << n;
  return x | t;
}

