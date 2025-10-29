#include <stdio.h>
#include <stdlib.h>

// Get maximum value in array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting sort for radix sort (sorts by specific digit)
void countingSortForRadix(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    // Store count of occurrences
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that it contains actual position
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy output array to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

// Radix Sort - O(d * (n + k)) where d is number of digits
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortForRadix(arr, n, exp);
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Mang sau khi sap xep (Radix Sort): ");
    printArray(arr, n);

    return 0;
}
