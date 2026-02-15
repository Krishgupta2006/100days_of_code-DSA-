#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter number of rows : ");
    scanf("%d", &m);
    printf("Enter number of columns : ");
    scanf("%d", &n);

    int matrix[m][n];
    int sum = 0;

    // Input matrix elements
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    for (int i = 0; i < m && i < n; i++)
    {
        sum += matrix[i][i];
    }

    // Print result
    printf("%d\n", sum);

    return 0;
}