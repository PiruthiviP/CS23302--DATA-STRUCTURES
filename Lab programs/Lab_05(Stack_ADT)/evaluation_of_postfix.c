//evaluation of postifx
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int x) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t != NULL) {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    struct Node *t;
    int x = -1;
    if (top != NULL) {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int isOperand(char x) {
    return x >= '0' && x <= '9';
}

int Eval(char *postfix) {
    int x1, x2, r = 0;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            x2 = pop();
            x1 = pop();
            switch (postfix[i]) {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            push(r);
        }
    }
    return pop();
}

int main() {
    char *postfix = "234*+82/-";
    printf("Result is %d\n", Eval(postfix));
    return 0;
}
