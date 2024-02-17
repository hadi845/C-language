#include<stdio.h>
float sum(float,float);
float sub(float,float);
float mul(float,float);
float div(float,float);
void main()
{
    float num1,num2,result;
    printf("Enter number 1:");
    scanf("%f",&num1);
    printf("Enter number 2:");
    scanf("%f",&num2);
    result=sum(num1,num2);
    printf("\nsum=%.2f",result);
    result=sub(num1,num2);
    printf("\nsub=%.2f",result);
    result=mul(num1,num2);
    printf("\nproduct=%.2f",result);
    result=div(num1,num2);
    printf("\ndiv=%.2f",result);
}
float sum(float n1,float n2)
{
    float result;
    result=n1+n2;
    return result;
}
float sub(float n1,float n2)
{
    float result;
    result=n1-n2;
    return result;
}
float mul(float n1,float n2)
{
    float result;
    result=n1*n2;
    return result;
}
float div(float n1,float n2)
{
    float result;
    result=n1/n2;
    return result;
}
