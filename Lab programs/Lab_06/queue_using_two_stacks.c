//queue using two stacks 
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int *arr;
};

struct Queue {
    struct Stack *st1;
    struct Stack *st2;
};

struct Stack* createStack(int size) {
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = size;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));
    return s;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == s->size - 1;
}

void push(struct Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = x;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

void enqueue(struct Queue *q, int x) {
    push(q->st1, x);
}

int dequeue(struct Queue *q) {
    int x = -1;
    if (isEmpty(q->st2)) {
        if (isEmpty(q->st1)) {
            printf("Queue Underflow\n");
            return x;
        } else {
            while (!isEmpty(q->st1)) {
                push(q->st2, pop(q->st1));
            }
        }
    }
    return pop(q->st2);
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
    int n = sizeof(A) / sizeof(A[0]);
    
    struct Queue q;
    q.st1 = createStack(n);
    q.st2 = createStack(n);
    
    printf("Enqueue: ");
    for (int i = 0; i < n; i++) {
        enqueue(&q, A[i]);
        printf("%d", A[i]);
        if (i < n - 1) {
            printf(" <- ");
        }
    }
    printf("\n");

    printf("Dequeue: ");
    for (int i = 0; i < n; i++) {
        printf("%d", dequeue(&q));
        if (i < n - 1) {
            printf(" <- ");
        }
    }
    printf("\n");

    return 0;
}
