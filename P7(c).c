#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node* front;
    struct node* rear;
};

void enqueue(struct queue* q,int value){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node
}

int main(){
    struct queue q;
    q.front = NULL;
    q.rear = NULL;
    int c, value;
    while(1){
        printf("\n\n***** MAIN MENU *****");
        printf("\n  1. Enqueue\n  2. Dequeue\n  3. Display\n  4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("\nEnter the value to enqueue : ");
            scanf("%d",&value);
            enqueue(&q,value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("\nEXITING...\n\n");
            exit(0);
        default:
            printf("\nInvalid Choice! Try again.");
            break;
        }
    }
}