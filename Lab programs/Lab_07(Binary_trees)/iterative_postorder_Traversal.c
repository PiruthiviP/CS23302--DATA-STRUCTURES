#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}*root=NULL;

struct queue{
    struct node **Q;
    int rear;
    int front;
    int size;
};

struct stack{
    struct node *data;
    struct stack *next;
}*top=NULL;

void push(struct stack **st, struct node *x){
    struct stack *t = (struct stack*)malloc(sizeof(struct stack));
    if(t == NULL){
        printf("Underflow\n");
    } else {
        t->data = x;
        t->next = *st;
        *st = t;
    }
}

struct node* pop(struct stack **st){
    struct node *x = NULL;
    struct stack *t;
    if(*st == NULL){
        printf("Empty\n");
    } else {
        t = *st;
        *st = (*st)->next;
        x = t->data;
        free(t);
    }
    return x;
}

void create(struct queue *q, int size){
    q->size = size;
    q->Q = (struct node **)malloc(q->size * sizeof(struct node *));
    q->front = q->rear = 0;
}

void enqueue(struct queue *q, struct node *x){
    if((q->rear + 1) % q->size == q->front){
        printf("Queue Full\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct node* dequeue(struct queue *q){
    struct node *x = NULL;
    if(q->front == q->rear){
        printf("Queue Empty\n");
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isempty(struct queue q){
    return q.front == q.rear;
}

void treecreate(){
    struct node *p, *t;
    struct queue q;
    int x;
    create(&q, 100);
    printf("Enter the root element: ");
    scanf("%d", &x);
    root = (struct node*)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while(!isempty(q)){
        p = dequeue(&q);
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1){
            t = (struct node*)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1){
            t = (struct node*)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void postorder(struct node *p)
{
    struct stack *st = NULL;  // Initialize stack pointer
    long int temp;
    
    while (p != NULL || top != NULL)
    {
        if (p != NULL)
        {
            push(&st, p);  // Push current node to stack
            p = p->lchild; // Move to left child
        }
        else
        {
            temp = (long int)pop(&st);  // Pop the stack
            if (temp > 0)
            {
                push(&st, (struct node*)(-temp));  // Mark node as visited
                p = ((struct node*)temp)->rchild;  // Move to right child
            }
            else
            {
                printf("%3d", ((struct node*)(-temp))->data);  // Print node data
                p = NULL;  // Set p to NULL to backtrack
            }
        }
    }
}

int main(){
    treecreate();
    postorder(root);
}