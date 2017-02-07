#include <inttypes.h>
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
  SIZE(int);
  SIZE(off_t);
  SIZE(size_t);
  SIZE(time_t);

  SIZE_STRUCT_MEM(timeval, tv_sec);
  SIZE_STRUCT_MEM(timeval, tv_usec);
  SIZE_STRUCT_MEM(timespec, tv_sec);
  SIZE_STRUCT_MEM(timespec, tv_nsec);
}
