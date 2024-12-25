//dequeue usinf array
#include <stdio.h>
#include <stdlib.h>

struct DEQueue {
    int front;
    int rear;
    int size;
    int* Q;
};

struct DEQueue* createDEQueue(int size) {
    struct DEQueue* dq = (struct DEQueue*)malloc(sizeof(struct DEQueue));
    dq->size = size;
    dq->front = -1;
    dq->rear = -1;
    dq->Q = (int*)malloc(dq->size * sizeof(int));
    return dq;
}

int isEmpty(struct DEQueue* dq) {
    return dq->front == -1 && dq->rear == -1;
}

int isFullRear(struct DEQueue* dq) {
    return dq->rear == dq->size - 1;
}

int isFullFront(struct DEQueue* dq) {
    return dq->front == 0;
}

void enqueueFront(struct DEQueue* dq, int x) {
    if (isFullFront(dq)) {
        printf("DEQueue Overflow at front\n");
    } else if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
        dq->Q[dq->front] = x;
    } else {
        dq->Q[--dq->front] = x;
    }
}

void enqueueRear(struct DEQueue* dq, int x) {
    if (isFullRear(dq)) {
        printf("DEQueue Overflow at rear\n");
    } else if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
        dq->Q[dq->rear] = x;
    } else {
        dq->Q[++dq->rear] = x;
    }
}

int dequeueFront(struct DEQueue* dq) {
    int x = -1;
    if (isEmpty(dq)) {
        printf("DEQueue Underflow at front\n");
    } else {
        x = dq->Q[dq->front];
        if (dq->front == dq->rear) {
            dq->front = dq->rear = -1;  // Queue becomes empty
        } else {
            dq->front++;
        }
    }
    return x;
}

int dequeueRear(struct DEQueue* dq) {
    int x = -1;
    if (isEmpty(dq)) {
        printf("DEQueue Underflow at rear\n");
    } else {
        x = dq->Q[dq->rear];
        if (dq->front == dq->rear) {
            dq->front = dq->rear = -1;  // Queue becomes empty
        } else {
            dq->rear--;
        }
    }
    return x;
}

void display(struct DEQueue* dq) {
    if (isEmpty(dq)) {
        printf("DEQueue is empty\n");
        return;
    }
    for (int i = dq->front; i <= dq->rear; i++) {
        printf("%d", dq->Q[i]);
        if (i < dq->rear) {
            printf(" <- ");
        }
    }
    printf("\n");
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
    int size = 10;

    struct DEQueue* dq = createDEQueue(size);

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        enqueueRear(dq, A[i]);
    }
    display(dq);

    enqueueRear(dq, 11);

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        dequeueFront(dq);
    }
    dequeueFront(dq);

    printf("\n");

    for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++) {
        enqueueFront(dq, B[i]);
    }
    display(dq);
    
    enqueueFront(dq, 10);
    enqueueFront(dq, 12);

    for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++) {
        dequeueRear(dq);
    }
    display(dq);

    dequeueRear(dq);
    dequeueRear(dq);

    free(dq->Q);
    free(dq);

    return 0;
}
