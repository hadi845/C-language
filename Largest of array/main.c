#include <stdio.h>
int main()
{
    int numbers[]={10, 5, 23, 17, 8};
    int size=5;
    int largest=numbers[0];
    for (int i=1;i<size;i++)
    {
        if(numbers[i]>largest)
        {
            largest=numbers[i];
        }
    }
    printf("The largest number is: %d\n", largest);
}
