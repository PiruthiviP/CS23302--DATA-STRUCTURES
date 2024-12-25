#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int power;
    struct node *next;
};


void create(struct node **list, int coeff[], int power[], int n) {
    struct node *last, *t;
    *list = (struct node *)malloc(sizeof(struct node));
    (*list)->coeff = coeff[0];
    (*list)->power = power[0];
    (*list)->next = NULL;
    last = *list;

    for (int i = 1; i < n; i++) {
        t = (struct node *)malloc(sizeof(struct node));
        t->coeff = coeff[i];
        t->power = power[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Function to display the polynomial (linked list)
void display(struct node *p) {
    while (p != NULL) {
        printf("%dx^%d ", p->coeff, p->power);
        if (p->next != NULL) printf("+ ");
        p = p->next;
    }
    printf("\n");
}

// Function to add two polynomials represented by linked lists
struct node* add(struct node *list1, struct node *list2) {
    struct node *poly1 = list1, *poly2 = list2;
    struct node *list3 = NULL, *poly3 = NULL, *last = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        poly3 = (struct node *)malloc(sizeof(struct node));

        if (poly1->power == poly2->power) {
            poly3->coeff = poly1->coeff - poly2->coeff;
            poly3->power = poly1->power;
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->power > poly2->power) {
            poly3->coeff = poly1->coeff;
            poly3->power = poly1->power;
            poly1 = poly1->next;
        } else {
            poly3->coeff = -poly2->coeff;
            poly3->power = poly2->power;
            poly2 = poly2->next;
        }

        poly3->next = NULL;

        if (list3 == NULL) {
            list3 = poly3;
        } else {
            last->next = poly3;
        }
        last = poly3;
    }

    

    return list3;
}

int main() {
    int coeff1[] = {5, 4, 2};
    int power1[] = {2, 1, 0};
    int n1 = sizeof(coeff1) / sizeof(coeff1[0]);

    int coeff2[] = {3, 6, 1};
    int power2[] = {2, 1, 0};
    int n2 = sizeof(coeff2) / sizeof(coeff2[0]);

    struct node *list1 = NULL, *list2 = NULL, *list3 = NULL;

    create(&list1, coeff1, power1, n1);
    create(&list2, coeff2, power2, n2);

    printf("Polynomial 1: ");
    display(list1);

    printf("Polynomial 2: ");
    display(list2);

    list3 = add(list1, list2);

    printf("Sum of Polynomials: ");
    display(list3);

    return 0;
}