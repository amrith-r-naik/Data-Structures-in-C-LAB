#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    return new_node;
}

void frontInsert(struct node **head, int value)
{
    struct node *new_node = createNode();
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
    printf("%d inserted succesfully in the front.", value);
}

void endInsert(struct node **head, int value)
{
    if (*head == NULL)
    {
        frontInsert(head, value);
        return;
    }
    struct node *new_node = createNode();
    new_node->data = value;
    new_node->next = NULL;
    struct node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    printf("%d inserted successfully in the end.", value);
}

void frontDelete(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nList Undeflow! Cannot delete.");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    int value = temp->data;
    free(temp);
    printf("\n%d deleted successfully from the front.", value);
}

void endDelete(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nList Undeflow! Cannot delete.");
        return;
    }
    if ((*head)->next==NULL){
        frontDelete(head);
        return;
    }
    struct node *temp_head = *head;
     while (temp_head->next->next != NULL){
        temp_head = temp_head->next;
    }
    struct node *temp = temp_head->next;
    temp_head->next = NULL;
    int value = temp->data;
    free(temp);
    printf("\n%d deleted successfully from the end.", value);
}

void displayAndCount(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nList Empty!\nNumber of nodes = 0");
        return;
    }
    struct node *temp_head = *head;
    int count = 0;
    printf("\nDISPLAYING THE SLL : \n");
    while (temp_head != NULL)
    {
        printf("%d  ", temp_head->data);
        temp_head = temp_head->next;
        count++;
    }
    printf("\nNumber of nodes = %d.", count);
}

int main()
{
    int c, value;
    struct node *head = NULL;
    while (1)
    {
        printf("\n\n***** MAIN MENU *****");
        printf("\n  1. Front Insert\n  2. End Insert\n  3. Front delete\n  4. End delete\n  5. Display and Count the number of nodes\n  6. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("\nEnter the value to be inserted : ");
            scanf("%d", &value);
            frontInsert(&head, value);
            break;
        case 2:
            printf("\nEnter the value to be inserted : ");
            scanf("%d", &value);
            endInsert(&head, value);
            break;
        case 3:
            frontDelete(&head);
            break;
        case 4:
            endDelete(&head);
            break;
        case 5:
            displayAndCount(&head);
            break;
        case 6:
            printf("\nEXITING...");
            exit(0);
            break;
        default:
            printf("\nINVALID CHOICE! Try again.");
            break;
        }
    }
}