#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *lchild;
    int data;
    int color; // 0 for Black, 1 for Red
    struct node *rchild;
} *root = NULL;

struct node *rotateLeft(struct node *p) {
    struct node *pr = p->rchild;
    p->rchild = pr->lchild;
    pr->lchild = p;
    return pr;
}

struct node *rotateRight(struct node *p) {
    struct node *pl = p->lchild;
    p->lchild = pl->rchild;
    pl->rchild = p;
    return pl;
}

void swapColors(struct node *x, struct node *y) {
    int temp = x->color;
    x->color = y->color;
    y->color = temp;
}

struct node *fixRedBlack(struct node *p) {
    if (p->rchild && p->rchild->color == 1) {
        if (p->lchild && p->lchild->color == 1) {
            p->lchild->color = 0;
            p->rchild->color = 0;
            p->color = 1;
        } else {
            p = rotateLeft(p);
            swapColors(p, p->lchild);
        }
    }
    if (p->lchild && p->lchild->color == 1 && p->lchild->lchild && p->lchild->lchild->color == 1) {
        p = rotateRight(p);
        swapColors(p, p->rchild);
    }
    return p;
}

struct node *rInsert(struct node *p, int key) {
    if (p == NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = key;
        newNode->color = 1; // New node is always Red
        newNode->lchild = NULL;
        newNode->rchild = NULL;
        return newNode;
    }
    if (key < p->data) {
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = rInsert(p->rchild, key);
    }
    return fixRedBlack(p);
}

void inorderTraversal(struct node *p) {
    if (p) {
        inorderTraversal(p->lchild);
        printf("%d ", p->data);
        inorderTraversal(p->rchild);
    }
}

int main() {
    int values[] = {10, 20, 30, 15, 25, 5, 1};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = rInsert(root, values[i]);
        root->color = 0; // Root is always black
    }
    inorderTraversal(root);
    return 0;
}