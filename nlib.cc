/* Exercise 5-5 */
#include <stdio.h>

void strncpy(char * s, char * t, int n)
{
    int c = 0;
    while(c++ < n && (*s++ = *t++));
}

char * strncat(char * s, char * t, int n)
{
    char * ret = s;
    int c = 0;
    for( ; *s != '\0'; s++);
    while(c++ < n && (*s++ = *t++));
    *s++ = '\0';

    return ret;
}

int strncmp(char * s, char * t, int n)
{
    int c = 0;
    while(c++ < n && (*s++ == *t++))
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int main()
{
    char a[] = "12345";
    char b[] = "67890";
    strncpy(a, b, 3);
    
    char c[] = "12345";
    char d[] = "67890";
    char * cat = strncat(c, d, 2);
    printf("cat = %s\n", cat);

    char e[] = "12345";
    char f[] = "77777";
    printf("strncmp(e, f) = %d", strncmp(e, f, 1));
}
