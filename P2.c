#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct stack
{
    int top;
    int items[MAX];
};

void push(struct stack*);
void pop(struct stack*);
void display(struct stack*);

int main(){
    struct stack st;
    int ch=-1,ele;
    st.top=-1;
    while(1){
        printf("\n\n***** MAIN MENU *****");
        printf("\n   1. Push");
        printf("\n   2. Pop");
        printf("\n   3. Display");
        printf("\n   4. Exit");
        printf("\nEnter your choice :");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            push(&st);
            break;
        case 2:
            pop(&st);
            break;
        case 3:
            display(&st);
            break;
        case 4: 
            printf("\n4. EXITING...");
            exit(0);
        default:
            printf("\nINVALID CHOICE!");
            break;
        }
    }
}

void push(struct stack* p){
    int value;
    if(p->top==MAX-1) printf("Stack Overflow! Cant push.");
    else{
        printf("\nPERFORMING PUSH :");
        printf("\nEnter the element to be pushed : ");
        scanf("%d",&value);
        p->items[++(p->top)]=value;
        printf("Push successful!");
    }
}

void pop(struct stack* p){
    if(p->top==-1) printf("\nStack Underflow! Cant pop.");
    else{
        printf("\nPERFORMING POP : ");
        p->top--;
        printf("\nPop successful!");
    }
}

void display(struct stack* p){
    if(p->top==-1){
        printf("\nStack Empty! Nothing to display.");
        return;
    }
    printf("\nDISPLAYING STACK STATUS: ");
    printf("\n[  ");
    for(int i=0;i<p->top;i++){
        printf("%d  |  ",p->items[i]);
    }
    printf("%d  ",p->items[p->top]);
    for(int i=0;i<MAX-1-p->top;i++){
        printf("|    ");
    }
    printf("]");
}