#include<stdio.h>

int any_odd_one(unsigned x);

int main() {
  printf("%d", any_odd_one(0x55555557));
  return 0;
}

int any_odd_one(unsigned x) {
  return (x & 0x55555555) == 0x55555555;
}
