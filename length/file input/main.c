#include <stdio.h>
#include <stdlib.h>

int isEven(const int NUM);
int isPrime(const int NUM);

void main() {
    FILE *fPtrIn, *fPtrEven, *fPtrOdd, *fPtrPrime;
    int num;

    fPtrIn = fopen("C:/Users/user/Documents/CODE BLOCKS/length/file input/input.txt", "a+");
    fPtrEven = fopen("C:/Users/user/Documents/CODE BLOCKS/length/file input/even.txt", "w+");
    fPtrOdd = fopen("C:/Users/user/Documents/CODE BLOCKS/length/file input/odd.txt", "w+");
    fPtrPrime = fopen("C:/Users/user/Documents/CODE BLOCKS/length/file input/prime.txt", "w+");

    if (fPtrIn == NULL || fPtrEven == NULL || fPtrOdd == NULL || fPtrPrime == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter numbers (enter -1 to stop):\n");

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        fprintf(fPtrIn, "%d\n", num);
    }

    rewind(fPtrIn);

    while (fscanf(fPtrIn, "%d", &num) != EOF) {
        if (isPrime(num))
        {
            fprintf(fPtrPrime, "%d\n", num);
            if (!isEven(num))
            {
                fprintf(fPtrOdd, "%d\n", num);
            }
        } else if (isEven(num))
        {
            fprintf(fPtrEven, "%d\n", num);
        } else
        {
            fprintf(fPtrOdd, "%d\n", num);
        }
    }

    fclose(fPtrIn);
    fclose(fPtrEven);
    fclose(fPtrOdd);
    fclose(fPtrPrime);
    printf("Data written to files successfully.\n");
}

int isEven(const int NUM)
{
    return (NUM % 2 == 0);
}

int isPrime(const int NUM)
{
    int i;

    if (NUM < 0)
        return 0;

    for (i = 2; i <= NUM / 2; i++)
    {
        if (NUM % i == 0)
        {
            return 0;
        }
    }

    return 1;
}


