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
    printf("created sucessfully\n");
}


void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%4d",p->data);
        p=p->next;
    }
    printf("\n");
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
 


void insert(int index, int x) {
 
    if (index < 0 || index > Length()){
        return;
    }
 
    struct node* p = first;
    struct node* t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
 
    if (index == 0){
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    } else {
        for (int i=0; i<index-1; i++){
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next){
            p->next->prev = t;
        }
        p->next = t;
    }
}
int main()

{
    int arr[]={1,2,3,4,4,6,7,8,9};
    create(arr,sizeof(arr)/sizeof(arr[0]));
    display(first);
    int pos,n;
    printf("Enter the number to insert:");
    scanf("%d",&n);
    printf("Enter the postion:");
    scanf("%d",&pos);
    insert(pos,n);
    display(first);
    
}
