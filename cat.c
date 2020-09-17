#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

void die(char *path) {
  perror(path);
  exit(1);
}

void output_file(char *path) {
  int fd;
  char buf[BUFFER_SIZE];
  int charlen;

  fd = open (path, O_RDONLY);
  if (fd < 0) {
    die(path);
  }

  for (;;) {
    charlen = read(fd, buf, sizeof buf);
    if (charlen < 0)
      die(path);
    if (charlen == 0)
      break;

    if (write(STDOUT_FILENO, buf, charlen) < 0)
      die(path);
  }

  if (close(fd) < 0)
    die(path);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage:  %s <filename>", argv[0]);
    die("");
  }
  for (int file_num = 1; file_num < argc; file_num++) {
    output_file(argv[file_num]);
  }
}
