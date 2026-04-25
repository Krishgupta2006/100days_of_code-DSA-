#include <stdio.h>

int main() {
    int n;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort Algorithm
    for(int i = 1; i < n; i++) {
        int key = arr[i];      // Current element
        int j = i - 1;

        // Shift elements greater than key to one position ahead
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at correct position
        arr[j + 1] = key;
    }

    // Output sorted array
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}