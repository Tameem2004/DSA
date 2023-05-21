//Implementing Queue using Circular Linked List

//header files
#include<stdio.h>
#include<stdlib.h>

//creating Linked List datastructure
typedef struct Node{
    int data;
    struct Node *next;
}Node;

//add element at end
void enqueue(Node** prear, int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*prear == NULL){
        *prear = newNode;
        newNode->next = *prear;
    }
    else{
        newNode->next = (*prear)->next;
        (*prear)->next = newNode;
        *prear = newNode;
    }
}

//delete element at beginning
void dequeue(Node** prear){
    if(*prear == NULL)
        printf("Queue Underflow\n");
    else{
        Node* ptr = (*prear)->next;
        if(ptr == *prear)
            *prear = NULL;
        else if(*prear != NULL){
            (*prear)->next = (*prear)->next->next;
            free(ptr);
        }
    }
}

//display element at rear end
void displayRear(Node** prear){
    if(*prear != NULL)
        printf("%d\n",(*prear)->data);
}

//display element at front end
void displayFront(Node** prear){
    if(*prear != NULL)
        printf("%d\n",(*prear)->next->data);
}

int main()
{
    system("cls");
    Node* rear;
    rear = NULL;
    int data, data2, choice;

    while(1){
        printf("\nCHOICES-\n1. ENQUEUE\n2. DEQUEUE\n3. SHOW FRONT\n4. SHOW REAR\n0. TO EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                enqueue(&rear,data);
                break;

            case 2:
                dequeue(&rear);
                break;

            case 3:
                displayFront(&rear);
                break;

            case 4:
                displayRear(&rear);
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid Case!\n");
        }
    }

    return 0;
}