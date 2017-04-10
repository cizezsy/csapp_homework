#include<stdio.h>

int threefourths(int x);

int main() {
  printf("%d", threefourths(-5));
  return 0;
}

int threefourths(int x) {
  int w = sizeof(int) << 3;
  int sign = x >> (w - 1);
  int n1 = (x + (sign & ((1 << 1) - 1))) >> 1;
  int n2 = (x + (sign & ((1 << 2) - 1))) >> 2;
  return n1 + n2;
}
