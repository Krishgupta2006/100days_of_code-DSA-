#include <stdio.h>

int main()
{
    int n;

    // Read the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Assume first element is both max and min
    int max = arr[0];
    int min = arr[0];

    // Traverse the array to find max and min
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];   // Update max
        }

        if(arr[i] < min)
        {
            min = arr[i];   // Update min
        }
    }

    // Print results
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}