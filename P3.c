#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct queue{
    int front;
    int rear;
    int items[MAX];
};

struct queue initialize();
void enqueue(struct queue*);
void dequeue(struct queue*);
void display(struct queue*);

int main(){
    struct queue q = initialize();
    int c;
    while(1){
        printf("\n\n***** MAIN MENU *****");
        printf("\n  1. Enqueue\n  2. Dequeue\n  3. Display\n  4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            enqueue(&q);
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

struct queue initialize(){
    struct queue q;
    q.front=-1;
    q.rear=-1;
    return q;
}

void enqueue(struct queue* p){
    int value;
    if(p->rear==MAX-1) printf("\nQueue Overflow! Can't perform enqueue.");
    else{
        printf("\nEnter the value to be enqueued : ");
        scanf("%d",&value);
        if(p->rear==-1){
            p->rear=p->front=0;
            p->items[p->rear]=value;
        }else{
            p->items[++(p->rear)]=value;
        }
        printf("%d ENQUEUED SUCCESSFULLY!",value);
    }
}

void dequeue(struct queue* p){
    int value;
    if(p->front==-1) printf("\nQueue Underflow! Can't perform dequeue.");
    else{
        value=p->items[p->front];
        if(p->front==p->rear) p->front=p->rear=-1;
        else ++(p->front);
        printf("\n%d DEQUEUED SUCCESSFULLY!",value);
    }
}

void display(struct queue* p){
    if(p->front==-1) printf("\nQueue empty! Cannot display.");
    else{
        printf("\nDISPLAYING THE QUEUE : \n");
        for(int i=p->front;i<=p->rear;i++) printf("%d  ",p->items[i]);
    }
}