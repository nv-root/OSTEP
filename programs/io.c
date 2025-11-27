#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

	int fd = open("./io.txt", O_WRONLY | O_CREAT | O_TRUNC | S_IRWXU);
	assert(fd > -1);

	int rc = write(fd, "Hello world\n", 13);
	assert(rc == 13);

	close(fd);


	return 0;
}
