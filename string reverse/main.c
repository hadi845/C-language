#include <stdio.h>
#include <string.h>
void main()
{
    char original[100], reversed[100];
    printf("Enter your name: ");
    scanf("%s", original);
    int length = strlen(original);
    for (int i = 0; i < length; i++)
        {
        reversed[i] = original[length - 1 - i];
        }
    printf("Original: %s\n", original);
    printf("Reversed: %s\n", reversed);
    if (strcmp(original, reversed) == 0)
    {
        printf("Reverse and original is same\n");
    } else
    {
        printf("Reverse and original is not same\n");
    }
}

