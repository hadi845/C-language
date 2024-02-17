#include <stdio.h>

void main()
 {
    int rows, i, j, space;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++)
        {

        for (space = 1; space <= rows - i; space++)
        {
            printf(" ");
        }

        for (j = 1; j <= i; j++)
        {
            printf("* ");
        }

        printf("\n");
    }

    for (i = rows; i >= 1; i--)
        {

        for (space = 1; space <= rows - i; space++)
        {
            printf(" ");
        }

        for (j = 1; j <= i; j++)
        {
            printf("* ");
        }

        printf("\n");
    }

}
