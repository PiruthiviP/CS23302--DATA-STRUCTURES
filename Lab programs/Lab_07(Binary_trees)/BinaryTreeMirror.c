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

void mirrorTree(TREE* root) {
    if (root == NULL) {
        return;
    }

    // Swap left and right children
    TREE* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively find the mirror for left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void preorder(TREE *p) {
    if (p) {
        printf("%3d", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

int main() {
    TREE *root = NULL;
    
    treecreate(&root);
    printf("Original Tree Preorder: ");
    preorder(root);
    printf("\n");

    mirrorTree(root);
    printf("Mirrored Tree Preorder: ");
    preorder(root);
    printf("\n");

    return 0;
}
/*
        1
       / \
      2   3
     / \   \
    4   5   6
    Original Tree Preorder: 1 2 4 5 3 6

        1
       / \
      3   2
     /   / \
    6   5   4
Mirrored Tree Preorder: 1 3 6 2 5 4

*/
