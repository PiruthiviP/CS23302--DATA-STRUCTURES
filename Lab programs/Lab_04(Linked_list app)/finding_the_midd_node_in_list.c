//to find the middle of the linked-lists--method 1
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL;
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
int Length() {
    int length = 0;
    struct node* p =first;
    while (p != NULL){
        length++;
        p = p->next;
    }
    return length;
}
int middle(struct node *p)
{
    int x;
    int c=Length()/2;
    for(int i=0;i<c;i++)
    {
        p=p->next;
    }
    x=p->data;
    return x ;
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
int main()
{
    
    int arr[]={1,23,4,5,66,6,7,89,9};
    create(arr,sizeof(arr)/sizeof(arr[0]));
    display(first);
    printf("The middle node of the element is:%d",middle(first));
}


