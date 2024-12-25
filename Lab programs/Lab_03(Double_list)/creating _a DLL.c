// creating in a double circular linked-list
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
} *first= NULL;

void create(int a[], int n) {
    struct node *last, *t;
   first= (struct node *)malloc(sizeof(struct node));
   first->data=a[0];
   first->next=first->prev=NULL;
   last=first;
   for(int i=1;i<n;i++)
   {
       t=(struct node *)malloc(sizeof(struct node));
       t->data=a[i];
       t->next=last->next;
       t->prev=last;
       last->next=t;
       last=t;
       
   }
    printf("created sucessfully");
}


int main()

{
    int arr[]={1,2,3,4,4,6,7,8,9};
    create(arr,sizeof(arr)/sizeof(arr[0]));
    display(first);
}
