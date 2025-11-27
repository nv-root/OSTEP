#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed");
  } else if (rc == 0) {
    close(STDOUT_FILENO);
    open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("p4.c");
    myargs[2] = NULL;
    execvp(myargs[0], myargs);
  } else {
    int wc = wait(NULL);
  }

  return 0;
}
