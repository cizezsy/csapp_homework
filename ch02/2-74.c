#include<stdio.h>

/* Determine whether arguments can be subtracted without overflow */
int tsub_ok(int x, int y);

int main() {
  printf("%d", tsub_ok(0x80000000, 6));
  return 0;
}

int tsub_ok(int x, int y) {
  int t = x - y;
  int w = (sizeof(int)) << 3;

  x = x >> (w - 1);
  y = y >> (w - 1);
  t = t >> (w - 1);

  int pos_over = ~x & y & t;
  int neg_over = x & ~y & ~t;
  int nor_over = ~(pos_over | neg_over);
  
  return (pos_over & 0) | (neg_over & 0) | (nor_over & 1);
 
}
