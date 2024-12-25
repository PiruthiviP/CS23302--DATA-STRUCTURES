#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int data;
    struct node *next;
};

// Function to create the linked list
void create(struct node **head, int arr[], int n) {
    struct node *last, *temp;
    *head = (struct node *)malloc(sizeof(struct node));
    (*head)->data = arr[0];
    (*head)->next = NULL;
    last = *head;

    for (int i = 1; i < n; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

// Function to display the linked list
void display(struct node *p) {
    while (p != NULL) {
        printf("%02d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// Function to compute the number represented by the linked list
long long computeNumber(struct node *head) {
    long long result = 0;
    int multiplier = 1;

    while (head != NULL) {
        result += head->data * multiplier;
        multiplier *= 100; // Each node represents two digits
        head = head->next;
    }

    return result;
}

int main() {
    struct node *head = NULL;
    int arr[] = {34, 12, 56}; // Linked list: 34 -> 12 -> 56 (Number: 561234)
    int n = sizeof(arr) / sizeof(arr[0]);

    create(&head, arr, n);

    printf("Linked List: ");
    display(head);

    long long number = computeNumber(head);

    printf("Number represented by the linked list: %lld\n", number);

    return 0;
}

