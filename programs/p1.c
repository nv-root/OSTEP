#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  printf("hello world (pid: %d)\n", (int)getpid());

  int rc = fork();
	// child starts from here
	// fork() returns 0 in the child process
	// fork() returns the child pid in the parent process
	// it's just a fucking if-else from there
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello, I am child (pid: %d)\n", (int)getpid());
  } else {
    printf("hello, I am parent of %d (pid: %d)\n", rc, (int)getpid());
  }

  return 0;
}
