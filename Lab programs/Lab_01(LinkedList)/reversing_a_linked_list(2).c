//program to reverse a linked list using sliding pointers
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


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
int reverse(struct node *p)
{
    p=first;
    struct node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
int main()
{
    
    int arr[]={1,4,5,6,7,8,9,9,9,9,89};
    create(arr,sizeof(arr)/sizeof(arr[0]));
    
   
    display(first);
    reverse(first);
    display(first);
  
    
    
}