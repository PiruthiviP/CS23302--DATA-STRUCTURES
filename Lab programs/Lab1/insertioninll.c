//program to insert operation in a  linked list
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
void insert(struct node *p,int x,int pos)
{
    struct node *t;
    if(pos==0)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=first;
        first=t;
        
    }
    else if(pos>0)
    {
        for(int i=0;i<pos-1&&p;i++)
        {
            p=p->next;
        }
        if(p)
        {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;
        }
        
    }
}
int main()
{
    
    int arr[]={1,23,4,5,6,6,7,8};
    create(arr,sizeof(arr)/sizeof(arr[0]));
    int n,pos;
    display(first);
    printf("Enter the element to insert:");
    scanf("%d",&n);
    printf("Enter the postion:");
    scanf("%d",&pos);
    insert(first,n,pos);
        display(first);
    
}