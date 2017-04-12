#include<stdio.h>
#include<limits.h>

typedef unsigned float_bits;

float_bits float_i2f(int i);

unsigned leftmost_one_loc(unsigned i);

float_bits f2u(float f);

float u2f(float_bits f);

int main() {
  for(int i = 0; i <= INT_MAX; i++) {
    if(i % 0x10000 == 0)
      printf("%d\n", i);
    float myself_cast = u2f(float_i2f(i));
    float normal_cast = (float)i;
    if(myself_cast != normal_cast) {
      printf("Failed\n%x: %x, %x\n", i, f2u(normal_cast), f2u(myself_cast));
      break;
    }
  }
  
  return 0;
}

float_bits float_i2f(int i) {
  if(i == 0) return 0;

  unsigned sign = i & INT_MIN;
  unsigned exp;
  unsigned frac;
  unsigned ui = (unsigned)i;
  
  if(sign == INT_MIN) {
    ui = ~ui + 1;
  }
  
  unsigned loc = leftmost_one_loc(ui);
  
  if(loc > 24) {
    unsigned abadon = ui & (1 << (loc - 25));
    unsigned end = ui & (1 << (loc - 24));
    if(abadon != 0) {
      if(end != 0 && (ui & ~(~0 << (loc - 25))) == 0) {
	ui += end;
      } else if((ui & ~(~0 << (loc - 25))) != 0){
	ui += (1 << (loc - 24));
      }
    }
    loc = leftmost_one_loc(ui);
    frac = (ui >> (loc - 24)) & 0x7fffff;
    
  } else {
    frac = (ui << (24 - loc)) & 0x7fffff;
  }
  
  exp = loc - 1 + 127;
  return sign | (exp << 23) | frac;
  
}

unsigned leftmost_one_loc(unsigned i) {
  int count = 0;
  while(i != 0) {
    count++;
    i >>= 1;
  }
  return count;
}

float_bits f2u(float f) {
  return *((unsigned *)&f);
}

float u2f(float_bits f) {
  return *((float *)(&f));
}
