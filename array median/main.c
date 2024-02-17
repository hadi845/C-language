#include <stdio.h>
void swap(int *,int *);
void sortarray(int[],int);
float calculatemedian(int[],int);
void main()
{
    int array[]={5,10,15,20,25,30};
    int arraysize=5;
    printf("Array elements: ");
    for(int i=0;i<arraysize;i++)
    {
        printf("%d ", array[i]);
    }
    float median= calculatemedian(array,arraysize);
    printf("Median of array is: %f", median);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortarray(int array[], int arraysize)
{
    int i,j;
    for(i=0;i<arraysize-1;i++)
    {
        for(j=0;j<arraysize-1;j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j],array[j+1]);
            }
        }
    }
}
float calculatemedian(int array[], int arraysize)
{
    sortarray(array,arraysize);
    if(arraysize%2!=0)
    {
        return array[arraysize/2];
    }
    else
    {
        return (array[arraysize/2]+array[arraysize/2-1])/2;
    }
}
