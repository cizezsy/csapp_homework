#include<stdio.h>
#include<limits.h>

/* Addition that saturates to Tmin or Tnax */
int saturating_add(int x, int y);

int main() {
  printf("%d", saturating_add(19, 8));
  return 0;
}

int saturating_add(int x, int y) {
  int t = x + y;
  int result = x + y;
  int w = sizeof(int) << 3;
  x = x >> (w - 1);
  y = y >> (w - 1);
  t = t >> (w - 1);
  int pos_over = ~x & ~y & t;
  int neg_over = x & y & ~t;
  int nor_over = ~(pos_over | neg_over);
  return (pos_over & INT_MAX) | (neg_over & INT_MIN) | (nor_over & result);
}
