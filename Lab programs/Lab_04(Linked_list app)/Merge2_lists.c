#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create(struct node **head, int a[], int n) {
    struct node *last, *t;
    *head = (struct node *)malloc(sizeof(struct node));
    (*head)->data = a[0];
    (*head)->next = NULL;
    last = *head;

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

struct node* merge(struct node *p, struct node *q) {
    struct node *newhead = NULL, *tail = NULL, *s = NULL;

    if (p == NULL)
        return q;
    if (q == NULL)
        return p;

    // First node selection for newhead
    if (p->data <= q->data) {
        s = p;
        p = p->next;
    } else {
        s = q;
        q = q->next;
    }

    newhead = s;
    tail = s;

    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            s->next = p;
            s = p;
            p = p->next;
        } else {
            s->next = q;
            s = q;
            q = q->next;
        }
    }

    // If either list has remaining nodes, link them
    if (p != NULL) {
        s->next = p;
    }
    if (q != NULL) {
        s->next = q;
    }

    return newhead;
}

int main() {
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6, 8};
    struct node *list1 = NULL, *list2 = NULL, *mergedList = NULL;

    create(&list1, a, 4);
    create(&list2, b, 4);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    mergedList = merge(list1, list2);

    printf("Merged List: ");
    display(mergedList);

    return 0;
}
