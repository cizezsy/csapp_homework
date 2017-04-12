#include<stdio.h>
#include<limits.h>

typedef unsigned float_bits;

int float_f2i(float_bits f);

float_bits f2u(float f);

float u2f(float_bits f);

int main() {
  for(unsigned i = 0; i < UINT_MAX; i++) {
    int normal_cast = (int)u2f(i);
    int myself_cast = float_f2i(i);
    if(normal_cast != myself_cast) {
      printf("failed\n%x: %x %x", i, normal_cast, myself_cast);
      break;
    }
  }
  return 0;
}

int float_f2i(float_bits f) {
  unsigned sign = f >> 31;
  unsigned exp = (f >> 23) & 0xff;
  unsigned frac = f & 0x7fffff;

  int e = exp - 127;
  
  if(e < 0)
    return 0;
  
  if(exp == 0xff || e >= 31) {
    return 0x80000000;
  }

  frac = frac | 0x800000;

  if(e <= 23)
    frac = frac >> (23 - e);
  else
    frac = frac << (e - 23);

  if(sign != 0)
    frac = (~(frac) + 1) | 0x80000000;


  return frac;
}

float_bits f2u(float f) {
  return *((unsigned *)&f);
}

float u2f(float_bits f) {
  return *((float *)(&f));
}
