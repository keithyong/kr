#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    while (--argc > 0)
        printf((argc > 1) ? "%s " : "%s", *++argv);
        /* same as printf("%s%s", *++argv, (argc > 1) ? " " : ""); */
    printf("\n");
    return 0;
}
