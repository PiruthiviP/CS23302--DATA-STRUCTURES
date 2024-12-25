#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *first = NULL;

void create(int a[], int n) {
    struct node *last, *t;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct node *p) {
    while (p != NULL) {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

struct node *findlongprefix(struct node *head1, struct node *head2) {
    struct node *result = NULL;
    struct node *tail = NULL;

    while (head1 != NULL && head2 != NULL && head1->data == head2->data) {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = head1->data;
        p->next = NULL;

        if (result == NULL) {
            result = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }

        head1 = head1->next;
        head2 = head2->next;
    }
    return result;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 6, 7, 8};

    struct node *list1 = NULL, *list2 = NULL;
    create(a, 5);
    list1 = first;

    create(b, 5);
    list2 = first;

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    struct node *commonPrefix = findlongprefix(list1, list2);

    printf("Longest Common Prefix: ");
    display(commonPrefix);

    return 0;
}
