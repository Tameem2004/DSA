#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int cap;
    int size;
    int *arr;
}Q;

void init(Q *q,int cap)
{
    q->front=-1;
    q->rear=-1;
    q->cap=cap;
    q->size=0;
    q->arr=(int*)malloc(cap*sizeof(int));
}

int isfull(Q *q);
int isempty(Q *q);
int enqueue(Q *q,int item);
int dequeue(Q *q);
int efront(Q *q);
int erear(Q *q);

int main()
{
    system("cls");
    Q q1;
    int Eq,Dq;
    int cap,ch,item;
    printf("Enter Capacity Of Queue");
    scanf("%d",&cap);
    init(&q1,cap);
    while(1)
    {
        printf("\nEnter Choice-");
        printf("\nEnd 0\nEnter Queue 1\nDelete Queue 2\nEfront 3\nErear 4\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                exit(1);
                break;
            case 1:
                printf("Enter Item");
                scanf("%d",&item);
                Eq=enqueue(&q1,item);
                if(Eq==0)
                {
                    printf("\nQueue Is Overflow");
                }
                break;
            case 2:
                Dq=dequeue(&q1);
                if(Dq==404)
                {
                    printf("\nQueue Is Underflow");
                }
                else
                {
                    printf("\nThe Dequeue Element: %d",Dq);
                }
                break;
            case 3:
                printf("\nThe Front Element: %d",efront(&q1));
                break;
            case 4:
                printf("\nThe Rear Element: %d",erear(&q1));
                break;
            default:
                printf("You Give A Invalid Choice");
        }
    }
}

int isfull(Q *q)
{
    return(q->front==0 && q->rear==q->cap-1 || q->rear+1==q->front);
}

int isempty(Q *q)
{
    return(q->front==-1);
}

int enqueue(Q *q,int item)
{
    if(!isfull(q))
    {
        if(q->front==-1 && q->rear==-1)
        {
            q->front=q->rear=0;
        }
        else if(q->rear==q->cap-1)
        {
            q->rear=0;
        }
        else
        {
            q->rear=q->rear+1;
        }
        q->arr[q->rear]=item;
        q->size=q->size+1;
        return 1;
    }
    else 
    {
        return 0;
    }
}

int dequeue(Q *q)
{
    int item;
    if(!isempty(q))
    {
        item=q->arr[q->front];
        q->size=q->size-1;
        if(q->front==q->rear)
        {
            q->front=q->rear=-1;
        }
        else if(q->front==q->cap-1)
        {
            q->front=0;
        }
        else
        {
            q->front=q->front+1;
        }
        return(item);
    }
    else 
    {
        return 404;
    }
}

int efront(Q *q)
{
    return(q->arr[q->front]);
}

int erear(Q *q)
{
    return(q->arr[q->rear]);
}