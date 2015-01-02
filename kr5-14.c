/*Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n is set to 10, let us say, but it can be changed by an optional argument so that
tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the input or the value of n. Write the program so it makes the best use of available storage; lines should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE    2000

void printStrArr(char *lineptr[], int len);
void enqueueLine(char *lineptr[], char *fresh, int nlines);
int mygetline(char s[], int lim);

int main(int argc, char *argv[]) {
    int n = 10;
    while (--argc > 0 && (*++argv)[0] == '-') {
        if ((*argv)[1])
            n = strtol(&(*argv)[1], NULL, 10);
        else
            printf("Bad option!");
    }
    char line[MAX_LINE];
    char* tail[n];
    int lineno = 0;
    char hello = 'h';

    while (mygetline(line, MAX_LINE) > 0)
    {
        if (lineno < n){
            tail[lineno] = line;
        }
        else
            enqueueLine(tail, line, n);
        printf("-----------------------\n");
        printStrArr(tail, n);
        lineno++;
    }
}

void enqueueLine(char *lineptr[], char *fresh, int nlines) {
    int i;
    for (i = 0; i < (nlines - 1); i++) {
        lineptr[i] = lineptr[i + 1];
    }
    lineptr[nlines - 1] = fresh;
}

void printStrArr(char *lineptr[], int len) {
    int i;
    for (i = 0; i < len; i++)
        printf("%s", lineptr[i]);
    putchar('\n');
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
