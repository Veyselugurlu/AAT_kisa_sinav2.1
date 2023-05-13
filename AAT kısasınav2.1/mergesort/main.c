#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main()
{
    int arr[10][10];
    int i, j;

    // Fill array with random numbers
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            arr[i][j] = rand() % 100;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Get start time
    clock_t start = clock();

    // Sort array using merge sort
    for (i = 0; i < 10; i++) {
        mergeSort(arr[i], 0, 9);
    }

    // Get end time
    clock_t end = clock();

    // Calculate total time
    double time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print total time
    printf("calisma suresi: %f saniye\n", time);

    return 0;
}


