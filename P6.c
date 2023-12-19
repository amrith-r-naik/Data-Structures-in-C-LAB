#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue();
void dequeue();
void display();

int main(){
    int c;
    while(1){
        printf("\n\n***** MAIN MENU *****");
        printf("\n  1. Enqueue\n  2. Dequeue\n  3. Display\n  4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
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

void enqueue(){
    int value;
    if((rear+1)%MAX==front) printf("\nQueue Overflow! Can't perform enqueue.");
    else{
        printf("\nEnter the value to be enqueued : ");
        scanf("%d",&value);
        if(rear==-1){
            rear=front=0;
            queue[rear]=value;
        }else{
            rear = (rear+1)%MAX;
            queue[rear]=value;
        }
        printf("%d ENQUEUED SUCCESSFULLY!",value);
    }
}

void dequeue(){
    int value;
    if(front==-1) printf("\nQueue Underflow! Can't perform dequeue.");
    else{
        value=queue[front];
        if(front==rear) front=rear=-1;
        else front = (front+1)%MAX;
        printf("\n%d DEQUEUED SUCCESSFULLY!",value);
    }
}

void display(){
    if(front==-1) printf("\nQueue empty! Cannot display.");
    else{
        printf("\nDISPLAYING THE QUEUE : \n");
        int i = front;
        do{
            printf("%d  ",queue[i]);
            i = (i+1)%MAX;
        } while(i!=(rear+1)%MAX);
    }
}