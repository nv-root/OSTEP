#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int fd = open("gibberish.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  int i;

  if (fd < 0) {
    perror("open failed");
    exit(1);
  }

  int rc = fork();

  if (rc < 0) {
    perror("fork failed");
    exit(1);
  } else if (rc == 0) {
    for (i = 0; i < 100; i++) {
      char child_msg[] =  "Child";
      write(fd, child_msg, strlen(child_msg));
    }
  } else {

    for (i = 0; i < 100; i++) {
      char parent_msg[] = "Parent";
      write(fd, parent_msg, strlen(parent_msg));
    }
  }

  close(fd);

  // they can access the same fd,
  return 0;
}
