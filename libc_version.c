#include <gnu/libc-version.h>
#include <stdio.h>

void print_macro_libc_version() {
  printf("macro libc version: %i.%i\n", __GLIBC__, __GLIBC_MINOR__);
}

void print_linked_libc_version() {
  printf("linked libc version: %s\n", gnu_get_libc_version());
}

void main() {
  print_macro_libc_version();
  print_linked_libc_version();
}
