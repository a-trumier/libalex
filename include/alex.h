#ifndef __ALEX__
#define __ALEX__

#define NULL (void*) 0

/* This is <probably> dumb but it keeps it simple. */
typedef int ssize_t;
typedef unsigned int size_t;
typedef unsigned short int umode_t;

/* SYSCALLS */
void exit(int);
ssize_t write(int, const void*, size_t);
ssize_t read(int, void*, size_t);
long int openat(int, const char*, int, umode_t);
long int close(unsigned int);
extern int syscall(unsigned int, ...);

/***********/
/* STDIO.H */
/***********/

typedef struct f
{
    /* In reality I think this is the ONLY thing that we care about. */
    short int fd;
} FILE;

/* Function stubs */

int fprintf(FILE* stream, const char* format, ...);
int printf(const char* format, ...);

/************/
/* STRING.H */
/************/

void* memchr(const void*, char, size_t);
int memcmp(const void*, const void*, size_t);
void* memcpy(void*, const void*, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, char, size_t);
char* strcpy(char*, const char*);
char* strncpy(char*, const char*, size_t);
char* strcat(char*, const char*);
char* strncat(char*, const char*, size_t);
int strcmp(const char*, const char*);
int strncmp(const char*, const char*, size_t);
char* strchr(const char*, char);
char* strrchr(const char*, char);
size_t strspn(const char*, const char*);
size_t strcspn(const char*, const char*);
char* strpbrk(const char*, const char*);
char* strstr(const char*, const char*);
size_t strlen(const char*);
char* strerror(int);
char* strtok(const char*, const char*);

#endif
