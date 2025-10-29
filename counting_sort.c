#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Counting Sort - O(n + k) where k is the range of input
void countingSort(int arr[], int n) {
    // Find the maximum element to determine range
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create count array and initialize with zeros
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Store count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    free(count);
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 88, 45, 50, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau: ");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    return 0;
}
