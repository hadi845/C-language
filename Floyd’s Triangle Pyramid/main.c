#include<stdio.h>
void main()
{
    int num=1;
    printf("Floyd's Triangle:\n");
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}
