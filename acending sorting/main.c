#include <stdio.h>
void main()
{
    int array[]={5,30,80,40,10};
    int arraysize=5;
    printf("Array elements: ");
    for(int i=0;i<arraysize;i++)
    {
        printf("%d ", array[i]);
    }
    for(int i=0;i<arraysize;i++)
    {
        for(int j=0;j<arraysize-i-1; j++)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    printf("\nArray in ascending order: ");
    for(int i=0;i<=4;i++)
    {
        printf("%d ", array[i]);
    }
    for(int i=0;i<arraysize;i++)
    {
        for(int j=0;j<arraysize-i-1; j++)
        {
            if(array[j]<array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
