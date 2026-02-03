#include <stdio.h>

int main()
{
    int n, key;
    int comp = 0;
    int foundIndex = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter a key you want to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++)
    {
        comp++;
        if (arr[i] == key)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        printf("Found at index %d\n", foundIndex);
    }
    else
    {
        printf("Not found!\n");
    }

    printf("Comparisons = %d\n", comp);

    return 0;
}