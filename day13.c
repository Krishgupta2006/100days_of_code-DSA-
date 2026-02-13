#include <stdio.h> // Required for printf() and scanf()

int main()
{

    int r, c;
    // r = number of rows
    // c = number of columns
    printf("Enter number of rows : ");
    scanf("%d", &r);
    printf("Enter number of columns : ");
    scanf("%d", &c);

    // Take input for rows and columns

    int matrix[r][c];
    // Declare a 2D array (matrix) of size r x c
    printf("Enter the elements of the matrix : \n");    
    for (int i = 0; i < r; i++)
    { // Loop through each row
        for (int j = 0; j < c; j++)
        {                               // Loop through each column
            scanf("%d", &matrix[i][j]); // Read each element
        }
    }

    int top = 0;        // Starting row index
    int bottom = r - 1; // Last row index
    int left = 0;       // Starting column index
    int right = c - 1;  // Last column index

    // Loop will continue until boundaries cross each other
    while (top <= bottom && left <= right)
    {

        // traverse top row (Left → Right)
        for (int i = left; i <= right; i++)
        {
            printf("%d ", matrix[top][i]);
            // Print elements of the top row
        }
        top++;
        // Move top boundary down (because top row is done)

        // traverse right column (Top → Bottom)
        for (int i = top; i <= bottom; i++)
        {
            printf("%d ", matrix[i][right]);
            // Print elements of the rightmost column
        }
        right--;
        // Move right boundary left (because right column is done)

        // traverse bottom row (Right → Left)
        // Only if there is still a valid row remaining
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                printf("%d ", matrix[bottom][i]);
                // Print elements of the bottom row in reverse
            }
            bottom--;
            // Move bottom boundary up
        }

        // transverse left column (Bottom → Top)
        // Only if there is still a valid column remaining
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                printf("%d ", matrix[i][left]);
                // Print elements of the leftmost column upward
            }
            left++;
            // Move left boundary right
        }
    }

    return 0;
    // End of program
}