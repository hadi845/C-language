#include<stdio.h>
void main()
{
    int num;
    printf("Enter a NUMBER to check IF its EVEN or ODD:");
    scanf("%d",& num);
    if(num%2==0)
        printf("%d is an EVEN number",num);
    else
        printf("%d is an ODD number",num);
}
