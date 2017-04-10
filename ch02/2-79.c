#include<stdio.h>

int mul3div4(int x);

int main() {
  return 0;
}

int mul3div3(int x) {
  x = (x << 1) + x;
  int w = sizeof(int) << 3;
  x >> (w - 1);
}
