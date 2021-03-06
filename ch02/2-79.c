#include<stdio.h>

int mul3div4(int x);

int main() {
  printf("%d", mul3div4(-6));
  return 0;
}

int mul3div4(int x) {
  int w = sizeof(int) << 3;
  int sign = x >> (w - 1);
  int n1 = (x + (sign & ((1 << 1) - 1))) >> 1;
  int n2 = (x + (sign & ((1 << 2) - 1))) >> 2;
  return n1 + n2;
}
