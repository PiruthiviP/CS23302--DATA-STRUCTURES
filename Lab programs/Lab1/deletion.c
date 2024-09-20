//program to insert a new list in a sorted list,
#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
    
} *first=NULL;
void create(int a[],int n)
{
    struct node *last,*t;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}
void display(struct node *p)
{
    p=first;
    while(p!=NULL)
    {
        printf("%4d",p->data);
        p=p->next;
    }
    printf("\n");
}
void sortedlist(struct node *p,int x)
{
    struct node *q=NULL,*t;
    p=first;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    while(p&&p->data<x)
    {
        q=p;
        p=p->next;
        
    }
    if(p=first)
    {
        t->next=first;
        first=t;
    }
    else
    {
    t->next=q->next;
    q->next=t;
    }
}

int main()
{
    
    int arr[]={1,4,5,6,7,8,9,9,9,9,89};
    create(arr,sizeof(arr)/sizeof(arr[0]));
    int n,pos;
    display(first);
    sortedlist(first,3);
     display(first);
    
    
    
}