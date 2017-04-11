#include<stdio.h>
#include<limits.h>

typedef unsigned float_bits;

/*Compute -f. If f is NaN, then return f */
float_bits float_negate(float_bits f);

float_bits f2u(float f);

float u2f(float_bits f);

int main() {
  for(float_bits i = 0; i < UINT_MAX; i++) {
    if(f2u((-u2f(i))) != float_negate(i) && float_negate(i) != i) {
      printf("failed\n %x:  %x != %x", i, (int)f2u((-u2f(i))), (int)float_negate(i));
      break;
    }
  }
  return 0;
}

float_bits float_negate(float_bits f) {
  int sign = f >> 31;
  int exp = (f >> 23) & 0xff;
  int frac = f & 0x7fffff;

  if(exp == 0xff && frac != 0)
    return f;

  return (~sign << 31) | (exp << 23) | frac; 
}

float_bits f2u(float f) {
  return *((unsigned *)&f);
}

float u2f(float_bits f) {
  return *((float *)(&f));
}
