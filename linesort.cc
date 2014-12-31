#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* Max #lines to be sorted */

char *lineptr[MAXLINES];    /* Pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lintptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */

int main()
{
    int nlines;     /* Number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000     /* max length of any input line */
int getline(char *, int);
char *alloc(int);

/* readliness: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';     /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

int getline(char *line, int lim)
{
    int c, i;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* qsort: sortv[left] ... v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)  /* Do nothing if array contains */
        return;
    swap(v, left, (left + right) /2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 10000             /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char * alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n;  /* old p */
    } else  /* not enough room */
        return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

