#include<stdio.h>
#include<conio.h>
int main()
{
    int num,rem;

    printf("enter number :- ");
    scanf("%d",&num);

    while (num>0)
    {
        rem=num%10;
        printf("%d",rem);
        num=num/10;
    }
    

    return 0;
}
