#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *rchild;
    int data;
    int height;
    struct node *lchild;
} *root = NULL;

int nodeheight(struct node *p) {
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int balfactor(struct node *p) {
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

struct node *llrotation(struct node *p) {
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeheight(p);
    pl->height = nodeheight(pl);

    if (p == root)
        root = pl;

    return pl;
}

struct node *lrrotation(struct node *p) {
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;

    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;
    plr->lchild = pl;
    plr->rchild = p;

    p->height = nodeheight(p);
    pl->height = nodeheight(pl);
    plr->height = nodeheight(plr);

    if (p == root)
        root = plr;

    return plr;
}

struct node *rrrotation(struct node *p) {
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = nodeheight(p);
    pr->height = nodeheight(pr);

    if (p == root)
        root = pr;

    return pr;
}

struct node *rlrotation(struct node *p) {
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;

    p->height = nodeheight(p);
    pr->height = nodeheight(pr);
    prl->height = nodeheight(prl);

    if (p == root)
        root = prl;

    return prl;
}


struct node *rinsert(struct node *p, int key) {
    struct node *t;
    if (p == NULL) {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->height = 1;
        t->rchild = t->lchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = rinsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = rinsert(p->rchild, key);

    p->height = nodeheight(p);

    // Balancing the tree
    if (balfactor(p) == 2 && balfactor(p->lchild) == 1)
        return llrotation(p);
    if (balfactor(p) == 2 && balfactor(p->lchild) == -1)
        return lrrotation(p);
    if (balfactor(p) == -2 && balfactor(p->rchild) == -1)
        return rrrotation(p);
    if (balfactor(p) == -2 && balfactor(p->rchild) == 1)
        return rlrotation(p);

    return p;
}


void inorder(struct node *p) {
    if (p != NULL) {
        inorder(p->lchild);
        printf("%4d", p->data);
        inorder(p->rchild);
    }
}

int main() {
    root = rinsert(root, 50);
    root = rinsert(root, 40);
    root = rinsert(root, 20);
    root = rinsert(root, 10);
    root = rinsert(root, 42);
    root = rinsert(root, 46);

    inorder(root);
    printf("\n");

    return 0;
}