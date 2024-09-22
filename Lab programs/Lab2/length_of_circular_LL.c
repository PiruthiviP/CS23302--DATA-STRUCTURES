// length of a single circular linked-list
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

int length(struct node *p)
{
    int ct=0;
    do{
        ct++;
        p=p->next;
    }while(p!=head);
    return ct;
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    create(arr, sizeof(arr) / sizeof(arr[0]));
   
    printf("The length of the list is %d",length(head));
    return 0;
}
