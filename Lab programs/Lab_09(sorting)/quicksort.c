#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    do {
        do { i++; } while (i <= high && arr[i] <= pivot);
        do { j--; } while (j >= low && arr[j] > pivot);
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);

    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        quicksort(arr, low, j);
        quicksort(arr, j + 1, high);
    }
}

int main() {
    int arr[] = {1, 4, 6, 9, 2, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}
