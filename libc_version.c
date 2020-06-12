#include <gnu/libc-version.h>
#include <stdio.h>

void main() {
  printf("GCC version: %s\n", gnu_get_libc_version());
}
