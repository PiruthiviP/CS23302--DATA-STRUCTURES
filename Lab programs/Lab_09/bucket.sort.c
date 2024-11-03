#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **bins, int idx) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = idx;
    temp->next = NULL;
    if (bins[idx] == NULL) {
        bins[idx] = temp;
    } else {
        struct node *p = bins[idx];
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

int delete(struct node **bins, int idx) {
    struct node *p = bins[idx];
    bins[idx] = bins[idx]->next;
    int x = p->data;
    free(p);
    return x;
}

int findmax(int arr[], int n) {
    int x = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > x)
            x = arr[i];
    }
    return x;
}

void Bucketsort(int arr[], int n) {
    int max = findmax(arr, n);
    struct node **bins = (struct node **)malloc((max + 1) * sizeof(struct node *));
    
    for (int i = 0; i <= max; i++)
        bins[i] = NULL;

    for (int i = 0; i < n; i++) {
        insert(bins, arr[i]);
    }

    int i = 0, j = 0;
    while (i <= max) {
        while (bins[i] != NULL) {
            arr[j++] = delete(bins, i);
        }
        i++;
    }

    free(bins);
}

int main() {
    srand(time(NULL));
    int arr[30];
    int n;
    printf("How many numbers do you want to enter: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 101;  

    printf("The elements before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    Bucketsort(arr, n);

    printf("\nThe sorted numbers are:\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    return 0;
}
