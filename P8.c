#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void frontInsert(struct node**, int);
void endInsert(struct node**, int);
void endDelete(struct node**);
void displayAndCount(struct node**);

int main(){
    struct node* tail = NULL;
    int c, value;
    system("clear");
    while (1)
    {
        printf("\n\n***** MAIN MENU *****");
        printf("\n  1. Front Insert\n  2. End Insert\n  3. End delete\n  4. Display and Count the number of nodes\n  5. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        system("clear");
        switch (c)
        {
        case 1:
            printf("\nEnter the value to be inserted : ");
            scanf("%d", &value);
            frontInsert(&tail, value);
            break;
        case 2:
            printf("\nEnter the value to be inserted : ");
            scanf("%d", &value);
            endInsert(&tail, value);
            break;
        case 3:
            endDelete(&tail);
            break;
        case 4:
            displayAndCount(&tail);
            break;
        case 5:
            printf("\nEXITING...\n");
            exit(0);
            break;
        default:
            printf("\nINVALID CHOICE! Try again.");
            break;
        }
    }
}

void frontInsert(struct node** tail, int value){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    if(*tail==NULL){
        *tail = new_node;
        new_node->next = *tail;
    }
    else{
        new_node->next = (*tail)->next;
        (*tail)->next = new_node;
    }
    printf("\nInserted %d at the front.",value);
}

void endInsert(struct node** tail, int value){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    if(*tail == NULL){
        frontInsert(tail, value);
        return;
    }
    new_node->next = (*tail)->next;
    (*tail)->next = new_node;
    *tail = new_node;
    printf("\nInserted %d at the end.",value);
}

void endDelete(struct node** tail){
    if(*tail == NULL){
        printf("\nList Underflow!");
        return;
    }
    if((*tail)->next == *tail){
        printf("\nDeleted %d from the end.",(*tail)->data);
        free(*tail);
        *tail = NULL;
        return;
    }
    struct node* current = (*tail)->next;
    while(current->next != *tail) current = current->next;
    current->next = (*tail)->next;
    printf("\nDeleted %d from the end.",(*tail)->data);
    free(*tail);
    *tail = current;
}

void displayAndCount(struct node** tail){
    if(*tail == NULL){
        printf("\nList empty!\nNumber of nodes = 0");
        return;
    }
    int count = 0;
    struct node* current = (*tail)->next;
    printf("\nDisplaying the List :\n");
    do{
        printf("%d  ",current->data);
        count++;
        current = current->next;
    }
    while(current!=(*tail)->next);
    printf("\nNumber of nodes = %d",count);
}