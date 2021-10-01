#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (chown(argv[1], 0, 0) == -1) {
    printf("chown fail\n");
  }
  else {
    printf("chown to root on %s succeeded\n", argv[1]);
  }
}