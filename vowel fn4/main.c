#include <stdio.h>
int Vowel(char);
void main()
{
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);
    if (Vowel(c))
     {
        printf("It is a vowel\n");
     } else
     {
        printf("It is a Consonant\n");
     }
}
int Vowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return 1;
    } else
    {
        return 0;
    }
}
