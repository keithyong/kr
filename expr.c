/* Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For example,
 * expr 2 3 4 + *
 * evaluates 2 * (3+4).*/
#include <stdio.h>
#include <stdlib.h>
 
int isOperator(char);
float eval(float, char, float);
struct node {
    char * str;
    node * next;
};

void printArr(float * a, int len)
{
    while (len--)
        printf("%.2f ", *a++);
    putchar('\n');
}

int main(int argc, char *argv[])
{
    float num[argc];
    int count = 0;
    /* Move argv pointer to the first operator
     * along the way, parse out the integers. */
    while (!isOperator(*(++argv)[0])){
        num[count] = (float)strtol(*argv, NULL, 10);
        count++;
        argc--;
    }
    int arrsize = count;
    for( ; argc-- > 1; count--, argv++){
        num[count - 2] = eval(num[count - 2], (*argv)[0], num[count - 1]);
    }
    printf("%.2f", num[0]);
}

float eval(float a, char op, float b)
{
    float ret = 0.0;
    switch(op) {
        case '*':
            ret = a * b;
            break;
        case '+':
            ret = a + b;
            break;
        case '-':
            ret = a - b;
            break;
        case '/':
            ret = a / b;
            break;
        default:
            printf("Illegal operator. If using *, must do \\*");
            break;
    }
    return ret;
}
int isOperator(char c)
{
    char * op = "*+-/";
    for( ; *op; op++)
        if (*op == c)
            return 1;
    return 0;
}
