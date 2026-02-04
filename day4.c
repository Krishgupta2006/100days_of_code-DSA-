#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of element: ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int left = 0;
    int right = n-1;
    while (left<right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
    printf("REVERSED ARRAY");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
    
    

    return 0;
}