#include <stdio.h>
void main()
{
    int first=0,second=1,next,i;
    printf("Fibonacci Series: ");

    for (i=0;i<10;i++)
    {
        if(i<=1)
            next=i;
        else
        {
            next=first + second;
            first=second;
            second=next;
        }
        printf("%d   ",next);
    }

}
