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

int compare(struct node *list1, struct node *list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->data != list2->data) {
            return 0; // Lists are not the same
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    // If both lists end at the same time, they are the same
    // If one list is longer, they are not the same
    return (list1 == NULL && list2 == NULL);
}

int main() {
    int a[] = {1, 3, 5, 7};
    int b[] = {1, 3, 5, 7,8};
    
    struct node *list1 = NULL, *list2 = NULL;

    create(&list1, a, 4);
    create(&list2, b, 5);
    

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    
  
    if (compare(list1, list2)) {
        printf("List 1 and List 2 are the same.\n");
    } else {
        printf("List 1 and List 2 are not the same.\n");
    }

    

    return 0;
}
