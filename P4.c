#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    int top;
    int items[MAX];
} stack;

void push(stack *, int);
int pop(stack *);
int evaluate(char[]);
int calc(char, int, int);
int power(int, int);

int main()
{
    int i = 0;
    char expr[MAX];
    printf("\nEnter the postfix expression : ");
    while ((expr[i++] = getchar()) != '\n')
        ;
    expr[--i] = '\0';
    printf("\nResult = %d", evaluate(expr));
}

int evaluate(char expr[])
{
    stack st;
    st.top = -1;
    char c;
    int i;
    int op1, op2, value;
    for (i = 0; (c = expr[i]) != '\0'; i++)
    {
        if (isdigit(c))
            push(&st, (int)(c - '0'));
        else
        {
            op2 = pop(&st);
            op1 = pop(&st);
            value = calc(c, op1, op2);
            push(&st, value);
        }
    }
    return pop(&st);
}

void push(stack *p, int value)
{
    p->items[++(p->top)] = value;
}

int pop(stack *p)
{
    return(p->items[(p->top)--]);
}

int calc(char c, int op1, int op2)
{
    switch (c)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '%':
        return op1 % op2;
    case '^':
        return power(op1, op2);
    }
}

int power(int x, int n){
    int value=1;
    for(int i=0;i<n;i++) value*=x;
    return value;
}