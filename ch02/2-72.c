#include<stdio.h>
#include<string.h>

/* Copy integer into buffer if space is available */
void copy_int(int val, void *buf, int maxbytes);

int main() {
  return 0;
}

void copy_int(int val, void *buf, int maxbytes) {
  int sizeOfInt = sizeof(val);
  if(maxbytes >= sizeOfInt) {
    memcpy(buf, (void *)&val, sizeof(val));
  }
}
