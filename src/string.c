#include <alex.h>

void* memchr(const void* buf, char c, size_t n)
{
    char* casted_buf = (char*) buf; 
    /* Cast here so we deal with 1 byte at a time */
    for (size_t i = 0; i < n; i++)
    {
        if (casted_buf[i] == c)
        {
            /* 
             * This is real cooked. We can't dereference void*, so first we
             * need to get to cast it to char*, then get the value at i, then
             * get the address of. Now we have the address of the character at
             * i, but we don't know if it's a character so we cast it back to
             * void*.
             */
            return (void*)(&((char*) buf)[i]);
        }
    }
    return NULL;
}

int memcmp(const void* buf1, const void* buf2, size_t n)
{
    int difference = 0;
    char* casted_buf1 = (char*) buf1;
    char* casted_buf2 = (char*) buf2;

    for (size_t i = 0; i < n; i++)
    {
        difference = difference + (casted_buf1[i] - casted_buf2[i]);
    }
    
    return difference;
}

void* memcpy(void* buf1, const void* buf2, size_t n)
{
    char* c_buf1 = (char*) buf1;
    char* c_buf2 = (char*) buf2;

    for (size_t i = 0; i < n; i++)
    {
        c_buf1[i] = c_buf2[i];
    }

    return buf1;
}

/* Naively assume both work? */
void* memmove(void* buf1, const void* buf2, size_t n)
{
    char* c_buf1 = (char*) buf1;
    char* c_buf2 = (char*) buf2;

    for (size_t i = 0; i < n; i++)
    {
        c_buf1[i] = c_buf2[i];
    }

    return buf1;
}

void* memset(void* buf, char byte, size_t n)
{
    char* c_buf = (char*) buf;

    for (size_t i = 0; i < n; i++)
    {
        c_buf[i] = byte;
    }

    return buf;
}

char* strcpy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char* strncpy(char* dest, const char* src, size_t n)
{
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    
    if (src[i] == '\0' && i < n)
        dest[i] = '\0';

    return dest;
}




