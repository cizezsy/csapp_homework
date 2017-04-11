#include<stdio.h>
#include<math.h>

typedef unsigned float_bits;

/* Compute |f|. If f is NaN then return f */
float_bits float_absval(float_bits f);

float_bits f2u(float f);

float u2f(float_bits f);


int main() {
  for(float_bits i = 0; i < UINT_MAX; i++) {
    float_bits float_result = fabsf(u2f(i));
    float_bits u_result = float_absval(i);
    if(float_result != u_result && u_result != i) {
      printf("failed\n %x:  %x != %x", i, float_result, u_result);
      break;
    }
  }
  return 0;
}

float_bits float_absval(float_bits f) {
  unsigned exp = (f >> 23) & 0xff;
  unsigned frac = f & 0x7fffff;

  if(exp == 0xff && frac != 0) {
    return f;
  }
  return 0 | (exp << 23) | frac;
  
}


float_bits f2u(float f) {
  return *((unsigned *)&f);
}

float u2f(float_bits f) {
  return *((float *)(&f));
}
