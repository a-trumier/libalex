#ifndef __ALEX__
#define __ALEX__

typedef int ssize_t;

typedef unsigned int size_t;

typedef unsigned int uint;

/* START OF SYSCALLS */
extern void exit(int);

extern ssize_t write(int, const void*, size_t);

#endif
