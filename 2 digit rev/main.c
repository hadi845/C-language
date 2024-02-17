#include<stdio.h>
void main()
{
    int number,num1,num2;
    printf("Enter a TWO digit number:");
    scanf("%d",& number);
    num1=number/10;
    num2=number%10;
    printf("Number in reversed order is %d%d",num2,num1);

}
