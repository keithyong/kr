#include <stdlib.h>
#include <stdio.h>

int main()
{
    float x = 3.2269;
    char buf[1000];
    sprintf(buf, "%.2f", x);
    printf("buf = %s", buf);
}
