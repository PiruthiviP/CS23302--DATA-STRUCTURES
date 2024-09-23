//polynomial representation using linked list
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure to represent a term in the polynomial
struct node {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
    struct node *next;  // Pointer to the next term
} *first = NULL;

// Function to create the polynomial linked list
void create(int coeff[], int exp[], int n) {
    struct node *last, *t;
    first = (struct node *)malloc(sizeof(struct node));  // Create the first node
    first->coeff = coeff[0];
    first->exp = exp[0];
    first->next = NULL;
    last = first;

    // Loop through the remaining terms and create nodes for them
    for (int i = 1; i < n; i++) {
        t = (struct node *)malloc(sizeof(struct node));
        t->coeff = coeff[i];
        t->exp = exp[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Function to evaluate the polynomial for a given value of x
double eval(int x) {
    double sum = 0.0;
    struct node *q = first;
    
    // Traverse the linked list and calculate the sum
    while (q != NULL) {
        sum += q->coeff * pow(x, q->exp);  // Use pow(x, exp) to calculate the term value
        q = q->next;
    }
    
    return sum;
}

// Function to display the polynomial in human-readable form
void display() {
    struct node *p = first;
    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next != NULL) {
            printf(" + ");
        }
        p = p->next;
    }
    printf("\n");
}

int main() {
    // Example input: Polynomial: 3x^3 + 5x^2 + 2x + 4
    int coeff[] = {3, 5, 2, 4};  // Coefficients of the terms
    int exp[] = {3, 2, 1, 0};    // Exponents of the terms
    int n = sizeof(coeff) / sizeof(coeff[0]);  // Number of terms in the polynomial

    // Create the polynomial
    create(coeff, exp, n);

    // Display the polynomial
    printf("Polynomial: ");
    display();

    // Evaluate the polynomial for x = 2
    int x = 2;
    printf("Value of the polynomial when x = %d: %.2f\n", x, eval(x));

    return 0;
}
