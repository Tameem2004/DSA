//Infix To Postfix
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct stack
{
    int top;
    int size;
    int *arr;
}stack;
void initialization(stack*s,int size)
{
    s->top=-1;
    s->size=size;
    s->arr=(char*)malloc(size*sizeof(char));
}
char *infix_to_postfix(char *inf,stack *s);
int isfull(stack *s);
void push(stack *s,char item);
int isempty(stack *s);
char pop(stack *s);
int isoperator(char ch);
int precedence(char ch);
char peek(stack *s);
int main()
{
    system("cls");
    stack s1;
    initialization(&s1,100); 
    char infix[100];
    printf("Enter The Infix Expression");
    gets(infix);
    char *postfix=infix_to_postfix(infix,&s1);
    printf("The Postfix Expression: %s ",postfix);
    return 0;
}
char *infix_to_postfix(char *inf,stack *s)
{
    int i,j;
    int ilen=strlen(inf);
    char *pf=(char*)malloc(ilen*sizeof(char));
    for(i=0,j=0;i<ilen;i++)
    {
        if(inf[i]==' '||inf[i]=='\t')
        {
            continue;
        }
        else if(isalnum(inf[i]))
        {
            pf[j++]=inf[i];
        }
        else if(inf[i]=='(')
        {
            push(s,inf[i]);
        }
        else if(inf[i]==')')
        {
            while (peek(s)!='(' && s->top>-1)
            {
                pf[j++]=pop(s);
            }
            if(s->top==-1 && s->arr[s->top+1]!='(')
            {
                return("Invalid Expression\n");
            }
            else
            {
                s->top--;
            }
        }
        else if(isoperator(inf[i]))
        {
            while(precedence(inf[i]<=precedence(peek(s)) && s->top>-1))
            {
                pf[j++]=pop(s);
            }
            push(s,inf[i]);
        }
    }
    while(s->top>-1)
    {
        pf[j++]=pop(s);
    }
    pf[j]='\0';
    return (pf);
}
int isfull(stack *s)
{
    return(s->top==s->size-1);
}
void push(stack *s,char item)
{
    if(!isfull(s))
    {
        s->arr[++s->top]=item;
    }
}
int isempty(stack *s)
{
    return(s->top==-1);
}
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
int precedence(char ch)
{
    if(ch=='^')
    {
        return(3);
    }
    else if(ch=='*'||ch=='/')
    {
        return(2);
    }
    else if(ch=='+'||ch=='-')
    {
        return(1);
    }
    else
    {
        return 0;
    }
}
char peek(stack *s)
{
    return(s->arr[s->top]);
}
