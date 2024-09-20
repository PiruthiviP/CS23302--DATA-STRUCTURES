//program to  recursive count in  a  linked list 
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
int Rcount(struct node *p)
{
    if(p!=NULL)
    return 1+Rcount(p->next);
    else 
    return 0;
}

int main()
{
    
    int arr[]={1,23,4,5,6,6,7,8};
    create(arr,sizeof(arr)/sizeof(arr[0]));
 
    printf("\n The count of the list is:%d",Rcount(first));
}