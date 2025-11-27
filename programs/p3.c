#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  printf("hello world (pid: %d)\n", (int)getpid());
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello, i am child (pid: %d)\n", (int)getpid());
    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("p3.c");
    myargs[2] = NULL;

    execvp(myargs[0], myargs); // same as running "wc p3.c"
		// exec() replaces the entire program with another one
    printf("this shouldn't print out"); // it didn't run 
  } else {
    int wc = wait(NULL);
    printf("hello, i am parent of %d (wc: %d) (pid: %d)\n", rc, wc,
           (int)getpid());
  }

  return 0;
}
