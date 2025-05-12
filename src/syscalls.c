#include <syscalls.h>

void exit(int code)
{
    syscall(93, code);
}

ssize_t write(uint fd, const void* buf, size_t size_of)
{
    int ret_val = syscall(64, fd, buf, size_of);
    return ret_val;
}

ssize_t read(uint fd, void* buf, size_t size_of)
{
    int ret_val = syscall(63, fd, buf, size_of);
    return ret_val;
}

lint close(uint fd)
{
    lint ret_val = syscall(57, fd);
    return ret_val;
}
