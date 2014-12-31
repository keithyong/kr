/* Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For example,
 * expr 2 3 4 + *
 * evaluates 2 * (3+4).*/
#include <stdio.h>
#include <stdlib.h>
 
int isOperator(char);
float eval(float, char, float);
struct node * parsedll(char **);
void printdll(struct node * head);
void removeNode(struct node * n);
void dllPushFront(struct node * curr, struct node * new);


typedef struct node {
    char * str;
    struct node * next;
    struct node * prev;
} node;

int main(int argc, char *argv[])
{
    node * head = parsedll(argv++);
    node * curr = head;
    printdll(head);
    float one, two, ans;
    char* currstr;

    for (; curr; curr = curr->next)
    {
        currstr = curr->str;
        printf("curr = %s\n", currstr);
        if (curr->next == NULL && curr->prev == NULL)
            printf("answer is %s", currstr);
        if (isOperator(currstr[0]))
        {
            printf("op found!\n");
            //if (curr->prev->prev->prev == NULL)
            //    return 0;
            one = strtof(curr->prev->prev->str, NULL);
            two = strtof(curr->prev->str, NULL);
            ans = eval(one, currstr[0], two);
            printf("%f %c %f = %f\n", one, currstr[0], two, ans);
            node *ansnode = malloc(sizeof *ansnode);
            ansnode->str = "322.22";
            dllPushFront(curr, ansnode);
            node **toRemove = &curr;
            removeNode(*toRemove);
            printdll(head);
        }
    }

    printdll(head);
}

void dllPushFront(node * curr, node * new)
{
    if (curr->next == NULL){
        new->next = NULL;
    } else {
        curr->next->prev = new;
        new->next = curr->next;
    }
    curr->next = new;
    new->prev = curr;
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

struct node * parsedll(char ** str)
{
    node* head;
    node** pr;
    node** curr = &head;

    for(; *str; str++)
    {
        *curr = malloc(sizeof **curr);
        (*curr)->str = *str;
        (*curr)->prev = *pr;
        pr = curr;
        curr = &(*curr)->next;
    }
    *curr = NULL;
    head->prev = NULL;
    return head;
}

void printdll(node * head)
{
    node * curr = head;
    while (curr)
    {
        printf("%s <-> ", curr->str);
        curr = curr->next;
    }
    putchar('\n');
}

void removeNode(node * n)
{
    node * nxt = n->next;
    node * prv = n->prev;
    if (nxt == NULL)
        prv->next = NULL;
    else if (prv == NULL) 
        nxt->prev = NULL;
    else {
        prv->next = nxt;
        nxt->prev = prv;
    }
}
