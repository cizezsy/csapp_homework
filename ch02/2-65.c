#include<stdio.h>

int odd_ones(unsigned x);

int main() {
  printf("%d", odd_ones(3));
  return 0;
}

int odd_ones(unsigned x) {
  x = (x >> 1) ^ x;
  x = (x >> 2) ^ x;
  x = (x >> 4) ^ x;
  x = (x >> 8) ^ x;
  x = (x >> 16) ^ x;
  return x & 1;
}
