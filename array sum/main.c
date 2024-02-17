#include<stdio.h>
void main()
{
    int marks1[3],sum;
    int marks2[3]={5,10,8};
    for(int i=0;i<=2;i++)
    {
        printf("Enter %d value:",i);
        scanf("%d",& marks1[i]);
    }
    for(int s=0;s<=2;s++)
    {
        sum=marks1[s]+marks2[s];
        printf("Sum of index %d is = %d\n",s,sum);
    }
}
