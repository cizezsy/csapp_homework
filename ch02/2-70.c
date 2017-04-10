#include<stdio.h>

int fits_bits(int x, int n);

int main() {
  printf("%x", fits_bits(8, 4));
  return 0;
}

int fits_bits(int x, int n) {
  int t = x >> (n - 1);
  return t == -1 || t == 0;
}
