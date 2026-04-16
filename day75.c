#include <stdio.h>

#define MAX 1000

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Hash map (array) to store first occurrence of sum
    int hash[2001]; // assuming sum range
    for(int i = 0; i < 2001; i++)
        hash[i] = -2;

    int offset = 1000; // to handle negative sums

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            maxLen = i + 1;

        if(hash[sum + offset] != -2) {
            int prevIndex = hash[sum + offset];
            if(i - prevIndex > maxLen)
                maxLen = i - prevIndex;
        } else {
            hash[sum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLenZeroSum(arr, n));
    return 0;
}