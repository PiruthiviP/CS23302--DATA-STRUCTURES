//innfinix to postfix with asscoiatuivy and precedence
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char ch) {
    if (s->top == MAX - 1) {
        return;
    }
    s->arr[++s->top] = ch;
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->arr[s->top--];
}

char top(struct Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->arr[s->top];
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')') {
        return 0;
    }
    return 1;
}

int outPrecedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 3;
    } else if (x == '^') {
        return 6;
    } else if (x == '(') {
        return 7;
    } else if (x == ')') {
        return 0;
    }
    return -1;
}

int inPrecedence(char x) {
    if (x == '+' || x == '-') {
        return 2;
    } else if (x == '*' || x == '/') {
        return 4;
    } else if (x == '^') {
        return 5;
    } else if (x == '(') {
        return 0;
    }
    return -1;
}

char* convert(char* infix) {
    char* postfix = (char*)malloc(strlen(infix) + 1);
    struct Stack stk;
    initStack(&stk);
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if (isEmpty(&stk) || outPrecedence(infix[i]) > inPrecedence(top(&stk))) {
                push(&stk, infix[i++]);
            } else if (outPrecedence(infix[i]) == inPrecedence(top(&stk))) {
                pop(&stk);
            } else {
                postfix[j++] = pop(&stk);
            }
        }
    }
    
    while (!isEmpty(&stk) && top(&stk) != ')') {
        postfix[j++] = pop(&stk);
    }
    
    postfix[j] = '\0';
    
    return postfix;
}

int main() {
    char infix[] = "((a+b)*c)-d^e^f";
    printf("%s\n", convert(infix));
    return 0;
}
