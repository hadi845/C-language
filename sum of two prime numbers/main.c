#include <stdio.h>
int sum(int n);
int main()
{
int a,num,f=0;
printf("Enter a number: ");
scanf("%d",&num);
for (a=2;a<=num/2;++a)
{
if(sum(a)==1)
{
if(sum(num-a)==1)
{
printf("%d can be expressed as sum of %d and %d.\n",num,a,num-a);
f=1;
}
}
}
if (f==0)
{
printf("%d cannot be expressed as sum of two prime numbers.",num);
return 0;
}
}
int sum(int n)
{
int b,ip=1;
for (b=2;b<=n/2;++b)
{
if(n%b==0)
{
ip=0;
break;
}
}
return ip;
}
