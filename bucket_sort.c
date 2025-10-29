#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    float data;
    struct Node *next;
} Node;

// Insert node in sorted order
void insertSorted(Node **head, float value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Bucket Sort - O(n) for uniformly distributed data
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    Node **buckets = (Node **)calloc(n, sizeof(Node *));

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in bucket
        insertSorted(&buckets[bucketIndex], arr[i]);
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node *current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(buckets);
}

// Print array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Mang sau khi sap xep (Bucket Sort): ");
    printArray(arr, n);

    return 0;
}
