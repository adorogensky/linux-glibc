#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/*
 * 1. while (bytes_read = read(...) > 0) was not working correctly, how is this expression evaluated?
 * 2. if 'dest' is opened without 'mode' param, its attributes will be set to ---- but i will still be able to remove and read it, how is this possible?
 */

const int BUFFER_SIZE = 4096;

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("usage: cp src dest\n");
    return 1;
  }

  int src = open(argv[1], O_RDONLY);
  if (src == -1) {
    perror("cannot open source file");
    return 1;
  }

  int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0640);
  if (dest == -1) {
    perror("cannot open destination file");
    return 1;
  }

  char buffer[BUFFER_SIZE];

  ssize_t bytes_read;
  while((bytes_read = read(src, buffer, BUFFER_SIZE)) > 0) {
    if (write(dest, buffer, bytes_read) == -1) {
      perror("cannot write to destination file");
      break;
    }
  }

  if (close(src) == -1) {
    perror("cannot close source file");
    return 1;
  }

  if (close(dest) == -1) {
    perror("cannot close destination file");
    return 1;
  }

  return 0;
}
