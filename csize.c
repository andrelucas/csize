#include <inttypes.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>

#define SIZE(type) printf("sizeof(" #type ") = %zu\n", sizeof(type))

#define SIZE_STRUCT_MEM(_st, _mem)                                             \
  do {                                                                         \
    struct _st _struct = {0};                                                  \
    printf("sizeof(struct " #_st "." #_mem ") = %zu\n", sizeof(_struct._mem)); \
  } while (0)

int main(int argc, char *argv[]) {
  SIZE(char);
  SIZE(bool);
  SIZE(int);
  SIZE(long);
  SIZE(long long);
  SIZE(off_t);
  SIZE(pid_t);
  SIZE(pthread_t);
  SIZE(size_t);
  SIZE(ssize_t);
  SIZE(time_t);
  SIZE(unsigned char);
  SIZE(unsigned int);
  SIZE(unsigned long);
  SIZE(unsigned long long);

  SIZE_STRUCT_MEM(timeval, tv_sec);
  SIZE_STRUCT_MEM(timeval, tv_usec);
  SIZE_STRUCT_MEM(timespec, tv_sec);
  SIZE_STRUCT_MEM(timespec, tv_nsec);

  // Char signedness.
  char c = 127;
  char c_plus_one = c + 1;

  if (c_plus_one < 0) {
    printf("(signed) char c_plus_one = 127 + 1 = %d\n", c_plus_one);
  } else {
    printf("(unsigned) char c_plus_one = 127 + 1 = %d\n", c_plus_one);
  }
}
