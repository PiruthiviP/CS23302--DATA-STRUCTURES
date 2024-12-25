#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* rinsert(struct Node* p, int key) {
    struct Node* t;
    if (p == NULL) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }
    if (key < p->data)
        p->left = rinsert(p->left, key);
    else if (key > p->data)
        p->right = rinsert(p->right, key);
    return p;
}

struct Node* removeLessThan(struct Node* root, int k) {
    if (root == NULL) {
        return NULL;
    }
    root->left = removeLessThan(root->left, k);
    root->right = removeLessThan(root->right, k);
    if (root->data < k) {
        struct Node* temp = root->right;
        free(root);
        return temp;
    }
    return root;
}

void preorder(struct Node* p) {
    if (p) {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = rinsert(root, 10);
    root = rinsert(root, 5);
    root = rinsert(root, 15);
    root = rinsert(root, 3);
    root = rinsert(root, 8);
    root = rinsert(root, 12);
    root = rinsert(root, 18);
    printf("Original Tree Preorder: ");
    preorder(root);
    printf("\n");
    root = removeLessThan(root, 10);
    printf("Tree after removing nodes less than 10: ");
    preorder(root);
    printf("\n");
    return 0;
}
/*
Original Tree Preorder: 10 5 3 8 15 12 18

After removing nodes with values less than 10, the updated preorder traversal will be:

Tree after removing nodes less than 10: 10 15 12 18*/