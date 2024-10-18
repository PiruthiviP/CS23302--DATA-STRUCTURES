#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL;

void insert(int key) {
    struct node *t = root;
    struct node *r = NULL, *p;

    if (root == NULL) {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL) {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return; // Duplicate key, do not insert
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

int height(struct node *p) {
    if (p == NULL)
        return 0;
    int x = height(p->lchild);
    int y = height(p->rchild);
    return (x > y ? x + 1 : y + 1);
}

struct node *inpre(struct node *p) {
    while (p && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

struct node *insucc(struct node *p) {
    while (p && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

struct node *delete(struct node *p, int key) {
    if (p == NULL)
        return NULL;

    if (key < p->data) {
        p->lchild = delete(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = delete(p->rchild, key);
    } else {
        // Node found
        if (p->lchild == NULL) {
            struct node *temp = p->rchild;
            free(p);
            return temp;
        } else if (p->rchild == NULL) {
            struct node *temp = p->lchild;
            free(p);
            return temp;
        } else {
            struct node *t;
            if (height(p->lchild) > height(p->rchild)) {
                t = inpre(p->lchild);
                p->data = t->data;
                p->lchild = delete(p->lchild, t->data);
            } else {
                t = insucc(p->rchild);
                p->data = t->data;
                p->rchild = delete(p->rchild, t->data);
            }
        }
    }
    return p;
}

void preorder(struct node *p) {
    if (p) {
        printf("%d  ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main() {
    insert(9);
    insert(15);
    insert(5);
    insert(20);
    insert(16);
    insert(8);
    insert(12);

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    root = delete(root, 15);
    printf("Preorder After Deleting 15: ");
    preorder(root);
    printf("\n");

    return 0;
}
