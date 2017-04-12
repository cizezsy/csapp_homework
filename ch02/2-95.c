#include<stdio.h>
#include<limits.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f);

float_bits f2u(float f);

float u2f(float_bits f);

int main() {
  for(unsigned i = 0; i < UINT_MAX; i++) {
    float_bits float_result = f2u(u2f(i) * 0.5);
    float_bits u_result = float_half(i);
    if(float_result != u_result && u_result != i) {
      printf("failed\n%x:  %x != %x", i, float_result, u_result);
      break;
    }
  }
}

float_bits float_half(float_bits f) {
  unsigned sign = f >> 31;
  unsigned exp = (f >> 23) & 0xff;
  unsigned frac = f & 0x7fffff;

  if(exp == 0xff)
    return f;
  
  if(exp == 0) {
    unsigned abadon = frac & 1;
    unsigned end = frac & 2;
    frac = frac >> 1;
    if(abadon == 1 && end == 2) {
      frac += 1;
    }
    return (sign << 31) | frac;
  }

  exp -= 1;
  if(exp == 0) { 
    unsigned abadon = frac & 1;
    unsigned end = frac & 2;
    frac = frac >> 1;
    frac = frac | 0x400000;
    if(abadon == 1 && end == 2) {
      frac += 1;
    }  
  }
    
  return sign << 31 | exp << 23 | frac; 
}

float_bits f2u(float f) {
  return *((unsigned *)&f);
}

float u2f(float_bits f) {
  return *((float *)(&f));
}
