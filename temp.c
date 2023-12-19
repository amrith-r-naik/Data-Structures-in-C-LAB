#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50

int st[MAX];
int top=-1;

int main(){
    char post[MAX];
    scanf("%s",post);
    printf("%d",eval(post));
}

push(int value){
    st[++top]=value;
}

int eval(char post[]){
    char symb;
    int i=0, op1,op2,result;
    for(symb=post[i];symb!='\n';i++){
        if(isdigit(symb)) push((int)(symb - '0'));
        else{
            op2 = pop();
            op1 = pop();
            result = calc(symb,op1,op2);
            push(result);
        }
    }
    return st[top];
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