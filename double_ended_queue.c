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
int front_enqueue(Q *q,int item);
int front_dequeue(Q *q);
int rear_enqueue(Q *q,int item);
int rear_dequeue(Q *q);
int efront(Q *q);
int erear(Q *q);

int main()
{
    Q q1;
    int Erq,Dfq,Efq,Drq;
    int cap,ch,item;
    printf("enter capacity of queue");
    scanf("%d",cap);
    init(&q1,cap);
    while(1)
    {
        printf("\nend 0");
        printf("\nrear_enqueue 1");
        printf("\nfront_dequeue 2");
        printf("\nfront_enqueue 3");
        printf("\nrear_dequeue 4");
        printf("\nefront 5");
        printf("\nerear 6");
        printf("\nenter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                exit(1);
                break;
            case 1:
                printf("enter item");
                scanf("%d",&item);
                Erq=rear_enqueue(&q1,item);
                if(Erq==0)
                {
                    printf("\nqueue is overflow");
                }
                break;
            case 2:
                Dfq=front_dequeue(&q1);
                if(Dfq==404)
                {
                    printf("\nqueue is underflow");
                }
                else
                {
                    printf("\nthe front dequeue element: %d",Dfq);
                }
                break;
            case 3:
                printf("enter item");
                scanf("%d",&item);
                front_enqueue(&q1,item);
                Efq=front_enqueue(&q1,item);
                if(Efq==0)
                {
                    printf("\nqueue is overflow");
                }
                break;
            case 4:
                Drq=front_dequeue(&q1);
                if(Drq==404)
                {
                    printf("\nqueue is underflow");
                }
                else
                {
                    printf("\nthe rear dequeue element: %d",Drq);
                }
                break;
            case 5:
                printf("\nthe front element: %d",efront(&q1));
                break;
            case 6:
                printf("\nthe rear element: %d",erear(&q1));
                break;
            default:
                printf("you give a invalid choice");
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

int rear_enqueue(Q *q,int item)
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

int front_dequeue(Q *q)
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

int front_enqueue(Q *q,int item)
{
    if(!isfull(q))
    {
        if(q->rear==-1 && q->front==-1)
        {
            q->rear=q->front=0;
        }
        else if(q->front==0)
        {
            q->front=q->cap-1;
        }
        else
        {
            q->front=q->front-1;
        }
        q->arr[q->front]=item;
        q->size=q->size+1;
        return 1;
    }
    else
    {
        return 0;
    } 
}

int rear_dequeue(Q *q)
{
    int item;
    if(!isempty(q))
    {
       item=q->arr[q->rear];
       q->size=q->size-1;
        if(q->front==q->rear)
        {
            q->rear=q->front=-1;
        }
        else if(q->rear==0)
        {
            q->rear=q->cap-1;
        }
        else
        {
            q->rear=q->rear-1;
        }
        return (item);
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