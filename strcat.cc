#include <stdio.h>

void mystrcat(char * s, char * t)
{
    for(;*s != '\0'; s++){}
    while((*s++ = *t++) != '\0'){}
}

int main()
{
    char one[1024] = "hello";
    char two[1024] = " world";
    mystrcat(one, two);
    printf("%s", one);
}
