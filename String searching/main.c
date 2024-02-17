#include<stdio.h>
#include<string.h>
void main()
{
    char masterlist[3][10]={"ZEESHAN","ZAKA","HADI"};
    char name[10];
    printf("Please verify your invitation by entering your name in CAP ");
    gets(name);
    int i, flag=0,cmp;
    for(i=0;i<=2;i++)
    {
    cmp= strcmp(name,&masterlist[i][0]);
    if(cmprao==0)
        {
            printf("We have successfully verified your invitation. WELCOME TO THE PARTY <3");
            flag=1;
            break;
        }
    }
    if (flag==0)
        printf("sorry, YOU ARE NOT INVITED </3");

}
