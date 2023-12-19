/* 1. Design, Develop and Implement a menu driven Program in C for the following 
(a) To create an Array of N Integer Elements and store n values. 
        -Inserting an Element (ELEM) at a given valid Position (POS)
        -Deleting an Element at a given valid Position POS)
        -Display of Array Elements
        -Exit.
Support the program with functions for each of the above operations.
*/

#include <stdio.h>
#include <stdlib.h>

// Function declarations
void insert(int ele, int pos);
void delete(int pos);
void display();

// Declaring the array and n  globally
int n, a[100];

void main()
{       
        int ele, pos;

        //Reading n
        printf("Enter a value for n : ");
        scanf("%d", &n);

        // Reading the array elements
        printf("Enter %d integers : \n", n);
        for (int i = 0; i < n; i++)
        {
                scanf("%d", &a[i]);
        }

        // While Loop for main menu
        int ch = 0;
        while (ch != 4)
        {
                printf("\n******** MAIN MENU ********");
                printf("\n1. Insert");
                printf("\n2. Delete");
                printf("\n3. Display");
                printf("\n4. Exit");

                printf("\nEnter your choice : ");
                scanf("%d", &ch);

                switch (ch)
                {
                case 1: printf("\n1. INSERTION");
                        //Read element and position to insert the element at
                        printf("\nEnter the element to be inserted :");
                        scanf("%d", &ele);
                        printf("Enter the position to be inserted at :");
                        scanf("%d", &pos);

                        //call insert function
                        insert(ele, pos);

                        break;

                case 2: printf("\n2. DELETION");
                        //Read the position of the element to be deleted
                        printf("\nEnter the position to delete the element:");
                        scanf("%d", &pos);

                        //call the delete function
                        delete(pos);
                        break;

                case 3: // call display function
                        display();
                        break;

                case 4: printf("4. Exiting....\n");
                        exit(0);
                        break;

                default:
                        printf("\nInvalid Choice!");
                        break;
                }
        }
}

void insert(int ele, int pos){
        /*LOGIC FOR INSERTION : when we insert an element at a position, the elements to the right of that positon are all shifted right.
        We can achieve this by :
                1.Start loop from one position after the last element
                2.Iterate backwards upto POS
                3.During each iteration make the current element as its previous element
                4. After loop increase n(denoting size of the array) by 1*/
        for(int i=n;i>pos;i--){
                a[i]=a[i-1];
        }
        a[pos]=ele;
        n+=1;
        printf("\nInserted %d succesfully at position %d!\n",ele,pos);
}

void delete(int pos){
        /* LOGIC FOR DELETION : When an element at a particular position is deleted all the elements to the right of that position gets shifted to left.
        This can be achieved by :
                1. Start loop from given POS
                2. Iterate forwar upto last but one element
                3. During each iteration make the current element as its next element
                4. After the loop decrease n(denoting the size of the array) by 1*/
        for(int i=pos;i<n-1;i++){
                a[i]=a[i+1];
        }
        n-=1;

        printf("\nDeletion at position %d succesful!\n",pos);
}

void display(){
        printf("\n3. DISPLAYING THE ARRAY\n");
        for(int i = 0; i < n; i++){
                printf("%d\t",a[i]);
        }
        printf("\n");
}