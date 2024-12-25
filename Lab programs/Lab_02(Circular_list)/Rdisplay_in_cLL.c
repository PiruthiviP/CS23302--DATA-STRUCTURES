// recursive display in a single circular linked-list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

void create(int a[], int n) {
    struct node *last, *t;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head; 
    last = head;

    for (int i = 1; i < n; i++) {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = head;
        last->next = t; 
        last = t; 
    }
    
}

void Rdisplay(struct node *p)
{
    static int flag =0;
    if(p!=head||flag==0)
    {
        flag=1;
        printf("%4d",p->data);
        Rdisplay(p->next);
    }
    flag=0;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    create(arr, sizeof(arr) / sizeof(arr[0]));
   
    Rdisplay(head);
    return 0;
}
