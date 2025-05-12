#include <alex.h>

/* This following function is from GeeksForGeeks. Thanks guys! */
void int_to_str(int N, char *str) {
    int i = 0;
  
    // Save the copy of the number for sign
    int sign = N;

    // If the number is negative, make it positive
    if (N < 0)
        N = -N;

    // Extract digits from the number and add them to the
    // string
    while (N > 0) {
      
        // Convert integer digit to character and store
      	// it in the str
        str[i++] = N % 10 + '0';
      	N /= 10;
    } 

    // If the number was negative, add a minus sign to the
    // string
    if (sign < 0) {
        str[i++] = '-';
    }

    // Null-terminate the string
    str[i] = '\0';

    // Reverse the string to get the correct order
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
}

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
