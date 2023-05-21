//Postfix_Evalution
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct stack
{
    int top;
    int size;
    char *arr;
}stack;
void init(stack *s,int size)
{
    s->top=-1;
    s->size=size;
    s->arr=(char*)malloc(size*sizeof(char));
}
void push(stack *s,char pos);
void postfix_evl(stack *s,char *pos);
int isfull(stack *s);
int isempty(stack *s);
char pop(stack *s);
int isoperator(char ch);
char peek(stack *s);
int main()
{
    system("cls");
    stack s1;
    init(&s1,100);
    char postfix[100];
    printf("Enter Postfix Expression");
    gets(postfix);
    postfix_evl(&s1,postfix);
    printf("Postfix Evolution : %c",peek(&s1));
    return 0;
}
//Condition For Stack Full
int isfull(stack *s)
{
    return(s->top==s->size-1);
}
//Push Element In Stack
void push(stack *s,char pos)
{
    if(!isfull(s))
    {
        s->arr[++s->top]=pos;
    }
}
//Condition For Stack Empty
int isempty(stack *s)
{
    return(s->top==-1);
}
//Pop Element From Stack
char pop(stack *s)
{
    if(!isempty(s))
    {
        return(s->arr[s->top--]);
    }
}
int isoperator(char ch)
{
    return(ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='^');
}
char peek(stack *s)
{
    return(s->arr[s->top]);
}
void postfix_evl(stack *s,char *pos)
{
    int ilen=strlen(pos);
    for(int i=0;i<ilen;i++)
    {
        if(pos[i]==' '||pos[i]=='\t')
        {
            continue;
        }
        else if (isdigit(pos[i]))
        {
            push(s,pos[i]);
        }
        else if(isoperator(pos[i]))
        {
            int a,b,c,d;
            int o1=pop(s);
            int o2=pop(s);
            o1=o1-48;
            o2=o2-48;
            switch(pos[i])
            {
                case '+':
                        a=o2+o1;
                        push(s,a+48);
                        break;
                case '-':
                        b=o2-o1;
                        push(s,b+48);
                        break;
                case '*':
                        c=o2*o1;
                        push(s,c+48);
                        break;
                case '/':
                        d=o2/o1;
                        push(s,d+48);
                        break;
                case '^':
                        d=pow(o1,o1);
                        push(s,d+48);
                        break;
            }
        }
    }
}