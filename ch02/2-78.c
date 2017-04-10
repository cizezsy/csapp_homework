#include<stdio.h>

/* Divide by oiwer if 2. Assume 0<= k <= w-1 */
int divide_power2(int x, int k);

int main() {
  printf("%d", divide_power2(-12340, 4));
  return 0;
}

int divide_power2(int x, int k) {
  int w = sizeof(int) << 3;
  int sign_bit = x >> (w - 1);
  return (x + (sign_bit & ((1 << k) - 1))) >> k;
}
