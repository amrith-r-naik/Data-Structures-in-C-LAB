#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct stack{
    struct node* top;
};

int isEmpty(struct stack* st){
    return st->top == NULL;
}

void push(struct stack* st, int value){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = st->top;
    st->top = new_node;
    printf("Pushed %d onto the stack.",value);
}

void pop(struct stack* st){
    if(isEmpty(st)){
        printf("\nStack Underflow!");
        return;
    }
    struct node* temp = st->top;
    st->top = st->top->next;
    printf("\nPopped %d from the stack.",temp->data);
    free(temp);
}

void display(struct stack* st){
    if(isEmpty(st)){
        printf("\nStack Empty!");
        return;
    }
    struct node* current = st->top;
    printf("\nDisplaying the stack : \n[top]---> ");
    while(current != NULL){
        printf("%d  ",current->data);
        current = current->next;
    }
}

int main(){
    struct stack st;
    st.top = NULL;
    int c, value;
    while(c!=4){
        printf("\n\n***** MAIN MENU *****");
        printf("\n   1. Push");
        printf("\n   2. Pop");
        printf("\n   3. Display");
        printf("\n   4. Exit");
        printf("\nEnter your choice :");
        scanf("%d",&c);

        switch (c)
        {
        case 1:
            printf("\nEnter the value to be pushed : ");
            scanf("%d",&value);
            push(&st,value);
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