#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

const char *USAGE_MSG = "usage: write_file <file_size>[kb|mb|gb] <buf_size>[kb|mb|gb]\n";

size_t size_in_bytes(char *multi_bytes) {
  char *err;
  size_t multi = 1, multi_bytes_int = strtol(multi_bytes, &err, 10);

  if (!*err) return multi_bytes_int;
  if (*(err + 1) != 'b') fprintf(stderr, USAGE_MSG), _exit(1);

  switch(*err) {
    case 'g' : multi *= 1024;
    case 'm' : multi *= 1024;
    case 'k' : multi *= 1024;
    default:
      if (multi > 1) return multi * multi_bytes_int;
      else fprintf(stderr, USAGE_MSG), _exit(1);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, USAGE_MSG);
    return 0;
  }

  size_t file_size = size_in_bytes(argv[1]);
  size_t buf_size = size_in_bytes(argv[2]);

  char *buf = malloc(buf_size);
  memset(buf, 0xFF, buf_size);

  int fd = open("dump", O_WRONLY | O_CREAT | O_TRUNC, 0640);

  size_t bytes_written, batch_size;

  while (bytes_written < file_size) {
    batch_size = file_size - bytes_written >= buf_size ? buf_size : file_size - bytes_written;
    bytes_written += write(fd, buf, batch_size);
  }

  close(fd);

  return 0;
}
