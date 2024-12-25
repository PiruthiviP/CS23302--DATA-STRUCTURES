//queue using array
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *Q;
} q;

void create(struct queue *q) {
    printf("Enter the size of the queue: ");
    scanf("%d", &q->size);
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front = q->rear = -1;
    printf("Queue created successfully\n");
}

void enqueue(struct queue *q, int x) {
    if (q->rear == q->size - 1)
        printf("Queue is full\n");
    else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct queue *q) {
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is empty\n");
    else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct queue q) {
    for (int i = q.front + 1; i <= q.rear; i++) {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main() {
    create(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    
    display(q);

    int x = dequeue(&q);
    if (x != -1) {
        printf("The deleted value is: %d\n", x);
    }
    display(q);

    return 0;
}