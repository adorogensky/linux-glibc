#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int BUFF_SIZE = 256;

int main() {
  char buff[4096];

  int fd = open("3", O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  int bytes_read;
  while ((bytes_read = read(fd, buff, 4096)) > 0) {
    printf("%.*s", bytes_read, buff);
  }

  if (bytes_read == -1 && errno == EISDIR) {
    fprintf(stderr, "cannot read from a directory\n");
    return 1;
  }

  return 0;
}
