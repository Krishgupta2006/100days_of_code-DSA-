#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int left, right;
    int Palindrome = 1;

    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            Palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (Palindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}