#include <stdio.h>
void main()
{
    int array[3][3];
    int i,j,sum=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
        printf("Enter array element[%d][%d]: ", i,j);
        scanf("%d,%d", &array[i][j]);
        }
    }
     for (int i=0;i<3;i++)
        {
        sum += array[i][i];
        }
    printf("Sum of diagonal elements is %d", sum);
}
