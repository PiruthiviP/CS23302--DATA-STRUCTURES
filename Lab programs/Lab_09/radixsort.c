#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **bins, int value, int idx) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (bins[idx] == NULL) {
        bins[idx] = temp;
    } else {
        struct node *p = bins[idx];
        while (p->next != NULL)
            p = p->next;
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

int count(int x) {
    int count = 0;
    while (x > 0) {
        x /= 10;
        count++;
    }
    return count;
}

void initializebins(struct node **p, int n) {
    for (int i = 0; i < n; i++) {
        p[i] = NULL;
    }
}

int getbinindex(int x, int idx) {
    return (int)(x / pow(10, idx)) % 10;
}

void radixsort(int arr[], int n) {
    int max = findmax(arr, n);
    int npass = count(max);
    struct node **bins = (struct node **)malloc(sizeof(struct node *) * 10);
    
    for (int pass = 0; pass < npass; pass++) {
        initializebins(bins, 10);

        for (int i = 0; i < n; i++) {
            int binidx = getbinindex(arr[i], pass);
            insert(bins, arr[i], binidx);
        }

        int i = 0, j = 0;
        while (i < 10) {
            while (bins[i] != NULL) {
                arr[j++] = delete(bins, i);
            }
            i++;
        }
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
        arr[i] = rand() % 100;

    printf("The elements before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    radixsort(arr, n);

    printf("\nThe sorted numbers are:\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    return 0;
}
