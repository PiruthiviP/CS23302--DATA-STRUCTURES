//stack using array(all operations)
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *s;
} st;

void create(struct stack *st) {
    printf("Enter the size of the stack: ");
    scanf("%d", &st->size);
    st->s = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

void push(struct stack *st, int x) {
    if (st->top == st->size - 1)
        printf("The stack is full\n");
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct stack *st) {
    int x = -1;
    if (st->top == -1) {
        printf("The stack is empty\n");
    } else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

void display(struct stack st) {
    for (int i = st.top; i >= 0; i--)
        printf("%d ", st.s[i]);
    printf("\n");
}

int peek(struct stack st, int pos) {
    if (pos <= 0 || pos > st.top + 1) {
        printf("Invalid position\n");
        return -1;
    } else {
        return st.s[st.top - pos + 1];
    }
}

int main() {
    create(&st); 
    push(&st, 30);  
    push(&st, 40); 
    push(&st, 50);  
    push(&st, 60);  
    push(&st, 70);  
    display(st);

    pop(&st);
    display(st);

    int position = 2;
    int value = peek(st, position);
    if (value != -1) {
        printf("Value at position %d from the top is %d\n", position, value);
    }

    return 0;
}