#include <alex.h>

int fprintf(FILE* stream, const char* format, ...)
{
    /*
     * First, we loop through the string looking for percentage signs. This 
     * will be the number of additional args.
     */

    int c = 0;
    int replacements = 0;
    while (format[c] != '\0')
    {
        if (format[c] == '%')
        {
            replacements++;
        }
        c++;
    }

    if (replacements == 0)
    {
        write(stream->fd, format, c);
        return 0;
    }

    int new_c = 0;
    int rep = 0;
    int placements[replacements]; 
    char type[replacements][4];
    /* Next, loop again noting where the replacements are. */
    while (format[new_c] != '\0')
    {
        if (format[new_c] == '%')
        {
            placements[rep] = new_c;
            new_c++;
            int i = 0;
            while (format[new_c] != ' ' || format[new_c] == '\0')
            {
                type[rep][i] = format[new_c];
                i++;
                new_c++;
            }
            rep++;
        }
    }

    /* 
     * Now we have the string of just the replacements and where they are
     * indexically in the string. Now we just need to make a new string,
     * convert the integers stored in the registers to strings themselves,
     * and concat it together.
     */
}
