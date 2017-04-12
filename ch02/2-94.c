#include<stdio.h>
#include<math.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f);

float_bits f2u(float f);

float u2f(float_bits f);

int main() {
  printf("%f", u2f(float_twice(0x7f000000)));
  return 0;
}

float_bits float_twice(float_bits f) {
  unsigned sign = (f >> 31);
  unsigned exp = (f >> 23) & 0xff;
  unsigned frac = f & 0x7fffff;

  if(exp == 0xff)
    return f;

  if(exp == 0) {
    return (sign << 31)| (frac << 1);
  } 

  unsigned e = exp - (0xff >> 1);
  exp = (e + 1) + (0xff >> 1);

  if(exp == 0xff) {
    frac = 0;
  }

  return sign << 31 | exp << 23 | frac;
}


float_bits f2u(float f) {
  return *((unsigned *)&f);
}

float u2f(float_bits f) {
  return *((float *)(&f));
}

