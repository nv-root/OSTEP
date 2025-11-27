#ifndef _COMMON_H
#define _COMMON_H

#include <sys/time.h>
#include <unistd.h>

#define MAX_CACHE_SIZE 1024 * 1024
#define MAX_OBJECT_SIZE 100 * 1024

static void Spin(int n) {
  struct timeval start, end;
  gettimeofday(&start, NULL);

  double elapsed;
  do {
    gettimeofday(&end, NULL);
    elapsed =
        (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
  } while (elapsed < n);
}

#endif
