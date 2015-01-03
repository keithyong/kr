#include <stdio.h>
int mygetline(char s[], int lim);
void printStrArr(char *lineptr[], int len);

int main()
{
    char * hi = "HI";
    char ** hiptr = &hi;
    char **secondptr = hiptr;
    char *arr[20];
    arr[0] = hi;
    arr[1] = *hiptr;

    printf("hi = %s, *hiptr = %s, *secondptr = %s", hi, *hiptr, *secondptr);
    printf("arr[0] = %s, arr[1] = %s", arr[0], arr[1]);

    char linebuf[3000];
    char *storage[300];
    int lineno = 0;

    while (mygetline(linebuf, 3000) > 0) {
        storage[lineno] = linebuf;
        printf("storage[lineno] = %s\n", storage[lineno]);
        lineno++;
    }
    printStrArr(storage, lineno);
    linebuf[0] = 'x';
    printStrArr(storage, lineno);
    char * p;
}

int mygetline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void printStrArr(char *lineptr[], int len) {
    int i;
    for (i = 0; i < len; i++)
        printf("%s", lineptr[i]);
    putchar('\n');
}
