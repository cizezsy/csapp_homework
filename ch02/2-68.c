#include<stdio.h>

/*
 * Mask with least signficant n bits set to 1
 */
int lower_one_mask(int n);

int main() {
  printf("%x", lower_one_mask(17));
  return 0;
}

int lower_one_mask(int n) {
  return ~(-1 << n);
}


