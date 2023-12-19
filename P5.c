#include <stdio.h>
#define MAX 100

char st[MAX];// globally declared array implementation of stack
int top = -1;

void push(char value){
    st[++top] = value;
}

int pop(){
    return st[top--];
}

int empty(){//returns true(1) if the stack is empty
    return top == -1;
}

int isoperand(char symb){ // return true if the symbol is an operand(ex. A,B,C,1,2,3,etc)
    return !(symb == '+' || symb == '-' || symb == '*' || symb == '/' || symb == '%' || symb == '^' || symb == '(' || symb == ')');
}

int prec(char top_element, char symb)// returns true if the operator in the top of the stack has higher precedence than the incoming symbol
{
    if (
        top_element == '+' && symb == ')' ||
        top_element == '-' && symb == ')' ||
        top_element == '*' && symb == '+' ||
        top_element == '*' && symb == '-' ||
        top_element == '*' && symb == ')' ||
        top_element == '/' && symb == '+' ||
        top_element == '/' && symb == '-' ||
        top_element == '/' && symb == ')' ||
        top_element == '%' && symb == '+' ||
        top_element == '%' && symb == '-' ||
        top_element == '%' && symb == '*' ||
        top_element == '%' && symb == '/' ||
        top_element == '%' && symb == ')' ||
        top_element == '^' && symb == '+' ||
        top_element == '^' && symb == '-' ||
        top_element == '^' && symb == '*' ||
        top_element == '^' && symb == '/' ||
        top_element == '^' && symb == ')' ||
        top_element == '(' && symb == ')')
        return 1;
    else
        return 0;
}

void postfix(char infix[]) // converts the infix expression to postfix, displaying it
{
    int i = 0;
    char symb;
    char popped;
    while ((symb = infix[i++]) != '\0') // main while loop that takes each character and assigns it to symb until /0 is found
    {
        // if the symb is operand directly display it
        if (isoperand(symb))
        {
            printf("%c", symb);
        }
        // else if it an operator, check the operator in the top of the list for precedence
        else
        {
            while (!empty() && prec(st[top], symb))// if the top operator has higher precendence than the incoming operator, pop it and display it
            {
                popped = pop();
                if (popped != '(' && popped != ')') // check if the operators are brackets because we should not display brackets
                    printf("%c", popped);
            }
            // if the top operator has lower precedence than the incoming operator, push the incoming operator onto the stack
            if(symb != ')') push(symb);
        }
    }
    // Once the last character in the infix string is scanned, pop all the remaining operators in the stack and display
    while (!empty())
    {
        popped = pop();
        if (popped != '(' && popped != ')') // do not display brackets
            printf("%c", popped);
    }
}

int main()
{
    int i = 0;
    char infix[MAX];
    
    // read an infix expression from the user
    printf("\nEnter the infix expression : ");
    while ((infix[i++] = getchar()) != '\n');
    infix[--i] = '\0';// make the \n as \0

    printf("The expression in postfix form will be : ");
    postfix(infix); // call the postfix() function
    printf("\n\n");

    return 0;
}
