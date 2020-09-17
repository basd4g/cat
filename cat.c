#include <stdio.h>
#include <stdlib.h>

void die() {
  exit(1);
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage:  %s <filename>", argv[0]);
    die();
  }
  printf("Hello,world!\n");
}
