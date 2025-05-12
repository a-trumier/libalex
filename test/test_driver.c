#include <alex.h>

int main()
{
    FILE stout;
    stout.fd = 1;
    fprintf(&stout, "We fprintf'd!\n");

    char* x = "Hi! I'm a void* buf.\n";
    void* y = memchr(x, 'a', 21);
    if (y != NULL)
    {
        fprintf(&stout, "Worked!\n");
    }

    char z[14];

    memcpy(z, "Do it!\n", 7);

    fprintf(&stout, z);

    char str[] = "foo-bar\n";
    memmove(&str[3], &str[4], 4);

    fprintf(&stout, str);

    char str2[] = "Stuffs\n";
    char str3[] = "Boats\n";

    fprintf(&stout, str2);

    strcpy(str2, str3);

    fprintf(&stout, str2);


    return 0;
}
