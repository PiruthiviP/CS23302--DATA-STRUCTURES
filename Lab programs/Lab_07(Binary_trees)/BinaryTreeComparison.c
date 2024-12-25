#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
} *root1 = NULL, *root2 = NULL;

struct queue {
    struct node **Q;
    int rear;
    int front;
    int size;
};

void create(struct queue *q, int size) {
    q->size = size;
    q->Q = (struct node **)malloc(q->size * sizeof(struct node *));
    q->front = q->rear = 0;
}

void enqueue(struct queue *q, struct node *x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("FULL");
        return;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct node* dequeue(struct queue *q) {
    struct node *x = NULL;
    if (q->front == q->rear) {
        printf("EMPTY");
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isempty(struct queue q) {
    return q.front == q.rear;
}

void treecreate(struct node **root) {
    struct node *p, *t;
    struct queue q;
    int x;
    create(&q, 100);
    printf("Enter the root element: ");
    scanf("%d", &x);
    *root = (struct node*)malloc(sizeof(struct node));
    (*root)->data = x;
    (*root)->lchild = (*root)->rchild = NULL;
    enqueue(&q, *root);
    while (!isempty(q)) {
        p = dequeue(&q);
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct node*)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct node*)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

int areTreesSame(struct node* tree1, struct node* tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }
    if (tree1 == NULL || tree2 == NULL) {
        return 0;
    }
    if (tree1->data != tree2->data) {
        return 0;
    }
    return areTreesSame(tree1->lchild, tree2->lchild) && areTreesSame(tree1->rchild, tree2->rchild);
}

void preorder(struct node *p) {
    if (p) {
        printf("%3d", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main() {
    treecreate(&root1);
    printf("Tree 1 Preorder: ");
    preorder(root1);
    printf("\n");
    
    treecreate(&root2);
    printf("Tree 2 Preorder: ");
    preorder(root2);
    printf("\n");
    
    if (areTreesSame(root1, root2)) {
        printf("The trees are the same.\n");
    } else {
        printf("The trees are not the same.\n");
    }

    return 0;
}
