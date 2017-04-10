#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void *calloc(size_t nmemb, size_t size); 

int main() {
  return 0;
}

void *calloc(size_t nmemb, size_t size) {
  if(nmemb == 0 || size == 0)
    return NULL;
  size_t sum = nmemb * size;
  if(sum / size != nmemb)
    return NULL;
  void *mem = malloc(sum);
  mem = memset(mem, 0, sum);
  return mem;
}
