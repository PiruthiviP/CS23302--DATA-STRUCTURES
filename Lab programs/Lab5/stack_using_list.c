//stack using linked list
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;
void push(int x)
{
    struct node*t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    printf("Full");
    else
    {
    t->data=x;
    t->next=top;
    top=t;
    }
}
int pop()
{
    int x;
    struct node*p;
    p=(struct node *)malloc(sizeof(struct node));
    if(top==NULL)
    printf("empty");
    
    else
    {
        p=top;
        top=top->next;
         x=p->data;
        free(p);
    }
    return x;
    
}
int peek(int pos)
{
    struct node *p=top;
    for(int i=0;i<pos-1&&p!=NULL;i++)
    p=p->next;
    if(p!=NULL)
    return p->data;
    
    return -1;
}
void display()
{
    struct node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    push(3);
    push(4);
    display();
    pop();
    display();
    return 0;
}