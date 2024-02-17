#include<stdio.h>
int sum(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
void main()
{
    int num1,num2,result;
    printf("Enter number 1:");
    scanf("%d",&num1);
    printf("Enter number 2:");
    scanf("%d",&num2);
    result=sum(num1,num2);
    printf("\nsum=%d",result);
    result=sub(num1,num2);
    printf("\nsub=%d",result);
    result=mul(num1,num2);
    printf("\nproduct=%d",result);
    result=div(num1,num2);
    printf("\ndiv=%d",result);
}
int sum(int n1,int n2)
{
    int result;
    result=n1+n2;
    return result;
}
int sub(int n1,int n2)
{
    int result;
    result=n1-n2;
    return result;
}
int mul(int n1,int n2)
{
    int result;
    result=n1*n2;
    return result;
}
int div(int n1,int n2)
{
    int result;
    result=n1/n2;
    return result;
}
