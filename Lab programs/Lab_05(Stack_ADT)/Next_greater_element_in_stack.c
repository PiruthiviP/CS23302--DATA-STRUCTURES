//next greater element using stack
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *s;
};

void create(struct stack *st, int size) {
    st->size = size;
    st->s = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

void push(struct stack *st, int x) {
    if (st->top == st->size - 1)
        printf("The stack is full\n");
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct stack *st) {
    if (st->top == -1) {
        printf("The stack is empty\n");
        return -1;
    } else {
        return st->s[st->top--];
    }
}

int top(struct stack *st) {
    if (st->top == -1) {
        return -1;  // Return -1 if stack is empty
    } else {
        return st->s[st->top];
    }
}

int isempty(struct stack *st) {
    return st->top == -1;
}

void nextGreaterElementCircular(int A[], int size) {
    int *nge = (int *)malloc(size * sizeof(int));  // To store next greater elements
    struct stack s;
    create(&s, size);
    
    // Initialize all elements in result as -1
    for (int i = 0; i < size; i++) {
        nge[i] = -1;
    }

    // Traverse the array twice to simulate the circular behavior
    for (int i = 0; i < 2 * size; i++) {
        int index = i % size;  // Circular index

        // Process elements in stack while the current element is greater than stack's top
        while (!isempty(&s) && A[top(&s)] < A[index]) {
            nge[top(&s)] = A[index];  // The next greater element for the top index in the stack
            pop(&s);  // Remove that index from the stack
        }

        // Only push the index during the first pass
        if (i < size) {
            push(&s, i);
        }
    }

    // Display the next greater elements
    for (int i = 0; i < size; i++) {
        printf("%d ", nge[i]);
    }
    printf("\n");

    free(nge);
}

int main() {
    // Example 1:
    int A[] = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};  // Input array
    int size = sizeof(A) / sizeof(A[0]);

    nextGreaterElementCircular(A, size);  // Expected output: 10, -1, 6, 6, 2, 6, 7, 7, 9, 9, 10

    // Example 2:
    int B[] = {5, 7, 1, 7, 6, 0};  // Input array
    int size2 = sizeof(B) / sizeof(B[0]);

    nextGreaterElementCircular(B, size2);  // Expected output: 7, -1, 7, -1, 7, 5

    return 0;
}
