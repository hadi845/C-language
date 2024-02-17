#include <stdio.h>
void main()
{
    int size,a,b,dc;
    printf("Enter the number of elements in array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements of array:\n");
    for (a = 0; a < size; a++)
    {
        printf("Enter element[%d] of array: ", a);
        scanf("%d", &arr[a]);
    }
    for (a = 0; a < size; a++)
    {
        dc = 1;
        for (b = a + 1; b < size; b++)
        {
            if (arr[a] == arr[b])
            {
                dc++;
                arr[b] = -1;
            }
        }
        if (dc > 1 && arr[a] !=-1)
        {
            printf("%d occurs %d times\n",arr[a],dc);
        }
    }
}

