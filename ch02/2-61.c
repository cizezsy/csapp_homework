#include<stdio.h>
#include<inttypes.h>

int evalue(int x);

int main() {
  printf("%d", evalue(-257));
  return 0;
}

int evalue(int x) {
  int w = sizeof(int) << 3;
  int highest = x >> (w - 8);
  int minest = (x + 1) << (w - 8);
  return !highest || !minest;
}

