//Doubly Linked Lists
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

void append(Node **phead1,Node **phead2,int data);
void insert_begin(Node **phead1,Node **phead2,int data);
void insert_after(Node *prev,int data);
void insert_before(Node *post,int data);

Node *searchkey(Node **phead1,int key);

void delend(Node **phead2);
void delbeg(Node **phead1);
void delafter(Node *prev);
void delbefore(Node *post);

int display_left(Node **phead2);
int display_right(Node **phead1);

int main()
{
    system("cls");
    Node *head1=NULL;
    Node *head2=NULL;
    int ch,data,item;
    while(1)
    {
        printf("Choice-\n");
        printf("   End 0\n");
        printf("   Append 1\n");
        printf("   Insert_begin 2\n");
        printf("   Insert_after 3\n");
        printf("   Insert_before 4\n");
        printf("   Delend 5\n");
        printf("   Delbeg 6\n");
        printf("   Delafter 7\n");
        printf("   Delbefore 8\n");
        printf("   Display_left 9\n");
        printf("   Display_right 10\n");
        printf("   Enter your choice-\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                exit(1);
                break;
            case 1:
                printf("Enter A Element");
                scanf("%d",&data);
                append(&head1,&head2,data);
                break;
            case 2:
                printf("Enter A Element");
                scanf("%d",&data);
                insert_begin(&head1,&head2,data);
                break;
            case 3:
                printf("Enter Element, After Which New Element To Be Entered");
                scanf("%d",&item);
                printf("Enter A Element");
                scanf("%d",&data);
                insert_after(searchkey(&head1,item),data);
                break;
            case 4:
                printf("Enter Element, Before Which New Element To Be Entered");
                scanf("%d",&item);
                printf("Enter A Element");
                scanf("%d",&data);
                insert_before(searchkey(&head1,item),data);
                break;
            case 5:
                delend(&head2);
                break;
            case 6:
                delbeg(&head1);
                break;
            case 7:
                printf("Enter Element, After Which Elemnt To Be Delete");
                scanf("%d",&item);
                Node *prev =searchkey(&head1,item);
                if(prev == head2->left)
                    delend(&head2);
                else if(prev!= NULL)
                    delafter(prev);
                break;
            case 8:
                printf("Enter Element, Before Which Elemnt To Be Delete");
                scanf("%d",&item);
                Node *post =searchkey(&head1,item);
                if(post == head1->right)
                    delbeg(&head1);
                else if(post!= NULL)
                    delbefore(post);
                break;
            case 9:
                display_left(&head2);
                break;
            case 10:
                display_right(&head1);
                break;
            default:
                printf("you give a invalid choice");
                break;
        }
    }
}

void append(Node **phead1,Node **phead2,int data)
{
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(*phead1==NULL)
    {
        *phead1=newnode;
        *phead2=newnode;
    }
    else
    {
        (*phead2)->right=newnode;
        newnode->left=*phead2;
        *phead2=newnode;
    }
}

void insert_begin(Node **phead1,Node **phead2,int data)
{
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(*phead1==NULL)
    {
        *phead1=newnode;
        *phead2=newnode;
    }
    else
    {
        (*phead1)->left=newnode;
        newnode->right=*phead1;
        *phead1=newnode;
    }
}

void insert_after(Node *prev,int data)
{
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->left=prev;
    newnode->right=prev->right;
    prev->right->left=newnode;
    prev->right=newnode;
}

void insert_before(Node *post,int data)
{
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->right=post;
    newnode->left=post->left;
    post->left->right=newnode;
    post->left=newnode;
}

Node *searchkey(Node **phead1,int key)
{
    Node *ptr;
    ptr=*phead1;
    while(ptr->right!=NULL && ptr->data!=key)
    {
        ptr=ptr->right;
    }
    if(ptr->data==key)
    {
        return ptr;
    }
    else
    {
        printf("\nElement Not Found\n");
    }
}

void delend(Node **phead2)
{
    if((*phead2)->left==NULL)
    {
        printf("\nElement Not Found\n");
    }
    else
    {
        Node *delnode=*phead2;
        delnode->left->right=NULL;
        *phead2=delnode->left;
        free(delnode);
    }
}
void delbeg(Node **phead1)
{
    if(*phead1==NULL)
    {
        printf("\nElement Not Found\n");
    }
    else
    {
        Node *delnode=*phead1;
        delnode->right->left=NULL;
        *phead1=delnode->right;
        free(delnode);
    }
}
void delafter(Node* prev)
{
    Node* delNode = prev->right;
    prev->right = delNode->right;
    delNode->right->left = prev;
    free(delNode);
}
void delbefore(Node* post)
{
    Node* delNode = post->left;
    post->left = post->left->left;
    delNode->left->right = post;
    free(delNode);
}
int display_left(Node **phead2)
{
    Node *ptr=*phead2;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->left;
    } while (ptr!=NULL);
}

int display_right(Node **phead1)
{
    Node *ptr=*phead1;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->right;
    } while (ptr!=NULL);   
}