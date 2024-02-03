#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
	int top;
	int size;
	int *arr;
}stack;

void init(stack *s,int size)
{
	s->top=-1;
	s->size=size;
	s->arr=(int*)malloc(size*sizeof(int));
}

int isfull(stack *s)
{
	return s->top==s->size;
}

int push(stack *s,int item)
{
	if(!isfull(s))
	{
		s->arr[s->top++]=item;
		return 0;
	}
	else
	{
		return 1;
	}
}

int isempty(stack *s)
{
	return s->top==-1;
}

int pop(stack *s)
{
	if(!isempty(s))
	{
		
		return s->arr[s->top--];
		return 0;
	}
	else
	{
		return 1;
	}
}

int multipop(stack *s,int limit)
{
	if(!isempty(s))
	{
		while(limit>0)
		{
			pop(s);
			--limit;
		}
		if(limit>s->top)
		{
			printf("Stack Is Emptied");
		}
	}
	else 
	{
		return 1;
	}
}

void display(stack *s)
{
	if(s->top==-1)
	{
		printf("Stack Is Empty");
	}
	for(int i=s->top;i>=0;i--)
	{
		printf("%d",s->arr[i]);
	}
}

int main()
{
	int size,ch,item,limit,b;
	stack s1;
	printf("Enter The Size Of Stack");
	scanf("%d",&size);
	init(&s1,size);
	
	printf("\nFor Exit Enter 0\nFor Push Enter 1\nFor Pop Enter 2\nFor Multipop Enter 3\nFor Show Enter 4");
	while(1)
	{
		printf("Enter Your Choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(1);
				break;
			case 1:
				printf("Enter Element For Push");
				scanf("%d",&item);
				int a=push(&s1,item);
				if(a==1)
				{
					printf("Stack Is Over Flow\n");
				}
				break;
			case 2:
				b=pop(&s1);
				if(b==1)
				{
					printf("Stack Is Under Flow\n");
				}
				else
				{
					printf("Popped %d From Stack",b);
				}
				break;
			case 3:
				printf("Enter How Many Element You Want To Pop");
				scanf("%d",&limit);
				int c=multipop(&s1,limit);
				if(c==1)
				{
					printf("Stack Is Under Flow\n");
				}
				break;
			case 4:
				display(&s1);
				break;
			default :
				printf("You Give A Invalid Choice");
			
		}
	}
}