#include<stdio.h>
void main()
{
    int arr1[2][2];int sum=0;int arr2[2][2]={10,30,40,50};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("Enter (%d,%d) element:",i,j);
            scanf("%d",& arr1[i][j]);
        }
    }
    for(int a=0;a<2;a++)
    {
        for(int b=0;b<2;b++)
        {
            sum=arr1[a][b]+arr2[a][b];
            printf("\nSUM of elements at (%d,%d) = %d",a,b,sum);
        }
    }

}
