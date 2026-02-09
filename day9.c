#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    printf("Enter a sentence:");
    scanf("%s", sentence);

    int len = strlen(sentence); //BY STRLEN WE CAN GET THE LENGTH OF THE STRING.

    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", sentence[i]);
    }

    return 0;
}