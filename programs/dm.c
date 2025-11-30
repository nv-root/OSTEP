#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	int *x = (int *)malloc(10 * sizeof(int));
	printf("%d\n", (int)sizeof(x));

	int y[10];
	printf("%d\n", (int)sizeof(y));

	char *src = "hello";
	// char *dst;
	char *dst = (char *)malloc(strlen(src) + 1);

	strcpy(dst, src); // accessing unallocated memory (dst) -> segmentation fault

	printf("%s", dst);
	return 0;
}
