#include<stdio.h>
void main()
{
    int a,b,c;
    printf("Enter First numbers:");
    scanf("%d",& a);
    printf("Enter Second numbers:");
    scanf("%d",& b);
    printf("before swap a=%d\tb=%d",a,b);
    c=a;
    a=b;
    b=c;
    printf("\nafter swap a=%d\t b=%d",a,b);
}
