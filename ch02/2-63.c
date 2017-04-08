#include<stdio.h>

unsigned srl(unsigned x, int k);

int sra(int x, int k);

int main() {
  printf("%d", sra(-6, 1));
  return 0;
}

unsigned srl(unsigned x, int k) {
  unsigned xsra = (int)x >> k;
  int w = sizeof(int) << 3;
  /* set the bit at w -> w - k  to 0 */
  return ~(-1 << (w - k)) & xsra;
}

int sra(int x, int k) {
  int xsrl = (unsigned)x >> k;
  int w = sizeof(int) << 3;
  /* if sign bit is 1, t = 0000011...111  
   * else t = 11111...1111
   */
  int t = (((1 << (w - k - 1)) & xsrl) << 1) - 1;
  /*set the bit at w -> w-k to the sign bit*/
  return ~t | xsrl;
}
