#include<stdio.h>
#include<limits.h>

int int_shifts_are_arithmetic();

int main() {
  printf("%d",int_shifts_are_arithmetic());
  return 0;
}

int int_shifts_are_arithmetic() {
  int w = sizeof(int) << 3;
  return (INT_MIN >> (w - 1)) == -1;
}
