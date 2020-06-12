#include <stdio.h>
#include <string.h>

const char *UNKNOWN_ERROR_MSG_PREFIX = "Unknown error";

void main() {
  for (int i = 0; i < 200; i++) {
    char *error_msg = strerror(i);
    if (
      strncmp(
        error_msg, UNKNOWN_ERROR_MSG_PREFIX,
        strlen(UNKNOWN_ERROR_MSG_PREFIX)
      ) != 0
    )
      printf("Error code %3i: %s\n", i, error_msg);
  }
}
