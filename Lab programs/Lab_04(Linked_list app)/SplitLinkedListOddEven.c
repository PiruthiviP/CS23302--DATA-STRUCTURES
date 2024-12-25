/*⁠Function to split a linked list into two lists, such that odd numbered nodes are in list1 and even numbered nodes are in list2. The new lists should not allocate any new memory.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *first = NULL; 


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
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// Function to split the linked list into odd and even numbered nodes
void splitList(struct node *head, struct node **list1, struct node **list2) {
    *list1 = NULL;
    *list2 = NULL;
    struct node *oddTail = NULL, *evenTail = NULL;
    
    int isOdd = 1;
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;

        if (isOdd) { // Odd numbered nodes
            if (*list1 == NULL) {
                *list1 = temp;
                oddTail = temp;
            } else {
                oddTail->next = temp;
                oddTail = temp;
            }
        } else { // Even numbered nodes
            if (*list2 == NULL) {
                *list2 = temp;
                evenTail = temp;
            } else {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        temp->next = NULL; // Break the link for the current node
        isOdd = !isOdd; // Toggle between odd and even
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    create(arr, n);

    printf("Original List: ");
    display(first);

    struct node *oddList = NULL, *evenList = NULL;
    splitList(first, &oddList, &evenList);

    printf("Odd List: ");
    display(oddList);

    printf("Even List: ");
    display(evenList);

    return 0;
}
