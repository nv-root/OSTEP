#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int x = 100;

	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
	}else if(rc == 0){
		x = 101;
		printf("after modifying x value in child: %d\n", x);
	}else{
		x = 102;
		printf("after modifying x value in parent: %d\n", x);
	}
	
	// child processes get their own address space 
  return 0;
}
