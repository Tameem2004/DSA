//Push & Pop Operation in a Stack
#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int top;
    int size;
    int *arr;
}stack;
void initialize(stack *s,int size)
{
    s->top=-1;
    s->size=size;
    s->arr=(int*)malloc(size*sizeof(int));
}
int isfull(stack *s);
int push(stack *s,int item);
int isempty(stack *s);
int pop(stack *s);
void display(stack *s);
int main()
{
    system("cls");
    int size,ch,item;
    stack s1;
    printf("Enter Size of Stack");
    scanf("%d",&size);
    initialize(&s1,size);
    printf("For Exit Press: 0");
    printf("\nFor Push Press: 1");
    printf("\nFor Pop Press: 2");
    printf("\nFor Show Press: 3");
    while(1)
    {
        printf("\nEnter Your Choice");
        scanf("%d",&ch);
        switch (ch)
        {  
            case 0:
                    exit(1);
                    break;
            case 1:
                    printf("Enter Number :");
                    scanf("%d",&item);
                    int a=push(&s1,item);
                    if(a==1)
                    {
                        printf("Stack Is Over Flow");
                    }
                    break;
            case 2:
                    item=pop(&s1);
                    if(item!=-1)
                    {
                        printf("Popped %d From Stack",item);
                    }
                    break;
            case 3:
                    display(&s1);
                    break;
            default :
                    printf("you give a invalid choice");
            
        }
    }
}
//Condition For Stack Full
int isfull(stack *s)
{
    return s->top==s->size-1;
}
//Push Element In Stack
int push(stack *s,int item)
{
    if(isfull(s))
    {
        return 1;
    }
    else
    {
        s->top++;
        s->arr[s->top]=item;
        return 0;
    }
}
//Condition For Stack Empty
int isempty(stack *s)
{
    return(s->top==-1);
}
//Pop Element From Stack
int pop(stack *s)
{
    if(isempty(s))
    {
       return 404;
    }
    else
    {
        return s->arr[s->top--];
        return 0;
    }
}
//Display Array
void display(stack *s)
{
    if(s->top==-1)
    {
        printf("stack is empty");
    }
    for(int i=s->top;i>=0;i--)
    {
        printf("%d ",s->arr[i]);
    }
}
