//paratheneses matching using stacks
//parathesis matching
#include<stdio.h>
#include<stdlib.h>
struct stack{
    char data;
 struct stack *next;
}*top=NULL;
void push(char x)
{
    struct stack *t;
    t=(struct stack*)malloc(sizeof(struct stack));
    if(t==NULL)
    printf("FUlL");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop()
{
    char x;
    struct stack *t;
    if(top==NULL)
    printf("empty");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
         return x;
}
int evaluate(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
    if(str[i]=='(')
    push(str[i]);
    else if(str[i]==')')
    {
    if(top==NULL)
    return 0;
    pop();
}
}
    if(top==NULL)
 return 1;
 else
 return 0;
}
int main()
{
char *exp="((a+b)*(c-d))";

printf("%d ",evaluate(exp));
}