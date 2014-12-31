/* Exercise 5-4 */
#include <stdio.h>

int strcmp(char * s, char * t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
int strend(char * s, char * t)
{
    int slen, tlen;
    slen = tlen = 0;
    char * tcpy = t;

    for (; *s != '\0'; s++)
        slen++;
    for (; *tcpy != '\0'; tcpy++)
        tlen++;

    if (!strcmp((s - tlen), t))
        return 1;

    return 0;
}

int main()
{
    char a[] = "Hello World";
    char b[] = "World";
    printf("%d\n", strend(a, b));
}
