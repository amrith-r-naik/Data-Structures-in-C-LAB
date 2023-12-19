#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

void frontInsert(struct node**, int);
void frontDelete(struct node**);
void endInsert(struct node**, int);
void endDelete(struct node**);
void displayAndCount(struct node**);

int main(){
    struct node* head = NULL;
    int c, value;
    system("clear");
    while (1)
    {
        printf("***** MAIN MENU *****\n");
        printf("  1. Front Insert\n  2. Front delete\n  3. End Insert\n  4. End delete\n  5. Display and Count the number of nodes\n  6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &c);
        system("clear");
        switch (c)
        {
        case 1:
            printf("Enter the value to be inserted : ");
            scanf("%d", &value);
            printf("\n");
            frontInsert(&head, value);
            break;
        case 2:
            frontDelete(&head);
            break;
        case 3:
            printf("Enter the value to be inserted : ");
            scanf("%d", &value);
            printf("\n");
            endInsert(&head, value);
            break;            
        case 4:
            endDelete(&head);
            break;
        case 5:
            displayAndCount(&head);
            break;
        case 6:
            printf("EXITING...\n");
            exit(0);
            break;
        default:
            printf("INVALID CHOICE! Try again.\n");
            break;
        } 
        printf("\n");
    }
}

void frontInsert(struct node** head, int value){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = *head;
    if(*head != NULL) (*head)->prev = new_node;
    *head = new_node;
    printf("Inserted %d in the front.\n",value);
}

void frontDelete(struct node** head){
    if(*head == NULL) printf("List Underflow!\n");
    else{
        struct node* temp = *head;
        if((*head)->next != NULL) (*head)->next->prev = NULL;
        *head = (*head)->next;
        printf("Deleted %d from the front.\n",temp->data);
        free(temp);
    }
}

void endInsert(struct node** head, int value){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    if(*head == NULL) *head = new_node;
    else{
        struct node* current = *head;
        while(current->next!=NULL) current = current->next;
        current->next = new_node;
        new_node->prev = current;
    }
    printf("Inserted %d at the end.\n",value);
}

void endDelete(struct node** head){
    if(*head == NULL) printf("List Underflow.\n");
    else{
        struct node* current = *head;
        while(current->next!=NULL) current = current->next;
        if(current->prev!=NULL) current->prev->next = NULL;
        else *head = NULL;
        printf("Deleted %d from the end.\n",current->data);
        free(current);
    }
}

void displayAndCount(struct node** head){
    if (*head == NULL) printf("List Empty!\nNumber of nodes = 0\n");
    else {
        struct node *current = *head;
        int count = 0;
        printf("DISPLAYING THE DLL : \n");
        while (current != NULL)
        {
            printf("%d  ", current->data);
            current = current->next;
            count++;
        }
        printf("\nNumber of nodes = %d.\n", count);
    }
}