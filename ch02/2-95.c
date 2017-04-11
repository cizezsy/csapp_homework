#include<stdio.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f);

float_bits f2u(float f);

float u2f(float_bits f);

int main() {
  return 0;
}

float_bits float_half(float_bits f) {
  unsigned sign = f >> 31;
  unsigned exp = (f >> 23) & 0xff;
  unsigned frac = f & 7fffff;

  if(exp == 0) {
    unsigned abadon = frac & 1;
    unsigned end = frac & 2;
    frac = frac >> 1;
    if(abadon == 1 && end == 1) {
      frac += 1;
    }
    return (sign << 31) | frac;
  }

  if(ex)
  
}

float_bits f2u(float f) {
  return *((unsigned *)&f);
}

float u2f(float_bits f) {
  return *((float *)(&f));
}
