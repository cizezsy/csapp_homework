#include<stdio.h>

int leftmost_one(unsigned x);

int main() {
  printf("%x", leftmost_one(0x3100));
  return 0;
}

int leftmost_one(unsigned x) {
  int t = ~x;
  t = t >> 1;
  x = t & x;
  t = (int)(t ^ x) >> 2;
  x = t & x;
  t = (int)(t ^ x) >> 4;
  x = t & x;
  t = (int)(t ^ x) >> 8;
  x = t & x;
  t = (int)(t ^ x) >> 16;
  return x & t;
}
