//program to search operation in a  linked list(recursive way)
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
struct node * Rsearch(struct node *p,int key)
{
    if(p==NULL)
    return NULL;
    if(key==p->data)
    return p;
    
    return Rsearch(p->next,key);
}
int main()
{
    
    int arr[]={1,23,4,5,6,6,7,8};
    create(arr,sizeof(arr)/sizeof(arr[0]));
    int key;
    printf("Enter the element to search:");
    scanf("%d",&key);
    struct node *temp=Rsearch(first,key);
    if(temp)
    {   
        printf("The element %d was found in the list.\n", temp->data);
    } 
    else {
        printf("The element %d was not found in the list.\n", key);
    }
    
}