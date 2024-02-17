#include<stdio.h>
void main()
{
    int num1,num2,num3,num4,sum,sub,mul,div,mod;
    printf("Enter First number=");
    scanf("%d",& num1);
    printf("Enter Second number=");
    scanf("%d",& num2);
    printf("Enter Third Number=");
    scanf("%d",& num3);
    printf("Enter Fourth number=");
    scanf("%d",& num4);
    sum=num1+num2+num3+num4;
    sub=num1-num2-num3-num4;
    mul=num1*num2*num3*num4;
    div=num1/num2/num3/num4;
    mod=num1%num2%num3%num4;
    printf("%d+%d+%d+%d=%d",num1,num2,num3,num4,sum);
    printf("\n%d-%d-%d-%d=%d",num1,num2,num3,num4,sub);
    printf("\n%dx%dx%dx%d=%d",num1,num2,num3,num4,mul);
    printf("\n%d/%d/%d/%d=%d",num1,num2,num3,num4,div);
    printf("\n%d mod %d mod %d mod %d=%d",num1,num2,num3,num4,mod);
}
