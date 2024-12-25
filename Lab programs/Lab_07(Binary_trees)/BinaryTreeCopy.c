#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} TREE;

struct queue {
    TREE** Q;
    int rear;
    int front;
    int size;
};

void create(struct queue *q, int size) {
    q->size = size;
    q->Q = (TREE**)malloc(q->size * sizeof(TREE*));
    q->front = q->rear = 0;
}

void enqueue(struct queue *q, TREE* x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("FULL");
        return;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

TREE* dequeue(struct queue *q) {
    TREE* x = NULL;
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

void treecreate(TREE **root) {
    TREE *p, *t;
    struct queue q;
    int x;
    create(&q, 100);
    printf("Enter the root element: ");
    scanf("%d", &x);
    *root = (TREE*)malloc(sizeof(TREE));
    (*root)->data = x;
    (*root)->left = (*root)->right = NULL;
    enqueue(&q, *root);
    
    while (!isempty(q)) {
        p = dequeue(&q);
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (TREE*)malloc(sizeof(TREE));
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            enqueue(&q, t);
        }

        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (TREE*)malloc(sizeof(TREE));
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(&q, t);
        }
    }
}

TREE* copyTree(TREE* root) {
    if (root == NULL) {
        return NULL;
    }

    TREE* newRoot = (TREE*)malloc(sizeof(TREE));
    newRoot->data = root->data;
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

void preorder(TREE *p) {
    if (p) {
        printf("%3d", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

int main() {
    TREE *root1 = NULL, *root2 = NULL;
    
    treecreate(&root1);
    printf("Tree 1 Preorder: ");
    preorder(root1);
    printf("\n");

    root2 = copyTree(root1);
    printf("Tree 2 (Copied) Preorder: ");
    preorder(root2);
    printf("\n");

    return 0;
}
