#include<stdio.h>
void main()
{
    int num,largest,smallest;
   printf("Enter an integer: ");
    scanf("%d", &num);
    largest = num;
    smallest = num;

    // Read the remaining four integers and update largest and smallest
    for (int i = 1; i < 5; i++) {
        printf("Enter an integer: ");
        scanf("%d", &num);

        if (num > largest) {
            largest = num;
        }
        if (num < smallest) {
            smallest = num;
        }
    }

    printf("The largest integer is: %d\n", largest);
    printf("The smallest integer is: %d\n", smallest);

}
