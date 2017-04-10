#include<stdio.h>
#include<limits.h>

int int_shifts_are_arithmetic();

int main() {
  printf("%d",int_shifts_are_arithmetic());
  return 0;
}

int int_shifts_are_arithmetic() {
  return (-1>>1) == -1;
}
