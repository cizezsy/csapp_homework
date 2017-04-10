#include<stdio.h>

/* the hign product of unsigned number multipy  */
unsigned unsigned_high_prod(unsigned x, unsigned y);

int main() {
  return 0;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
  int w = sizeof(int) << 3;
  int x_highest_bit = x >> (w - 1);
  int y_hignest_bit = y >> (w - 1);
  return signed_high_prod(x, y) + (x_highest_bit & y + y_hignest_bit & x));
}
