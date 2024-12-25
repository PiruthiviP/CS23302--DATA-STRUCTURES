//program to concatanete two lists
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node {
    int data;
    struct node *next;
} *first = NULL, *second = NULL;

void create(int a[], int n) {
    struct node *last, *t;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for(int i = 1; i < n; i++) {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int a[], int n) {
    struct node *last, *t;
    second = (struct node*)malloc(sizeof(struct node));
    second->data = a[0];
    second->next = NULL;
    last = second;
    for(int i = 1; i < n; i++) {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct node *p) {
    while(p != NULL) {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

void concat(struct node *p, struct node *q) {
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = q;
}

int main() {
    int arr[] = {1, 4, 5, 6, 7, 8, 9, 9, 9, 9, 89};
    create(arr, sizeof(arr)/sizeof(arr[0]));
    int arr2[] = {9, 8, 6, 5, 4, 3, 2};
    create2(arr2, sizeof(arr2)/sizeof(arr2[0]));

    display(first);
    display(second);
    concat(first, second);
    display(first);

    return 0;
}
