#include<stdio.h>
#include<conio.h>
int main()
{
    int num;
    printf("enter number :- ");
    scanf("%d",&num);

    if (num>0)
    {
        printf("number is positive");
    }
    else if (num<0)
    {
        printf("number is nagitive");
    }
    else
    {
        printf("its zero");
    }
    
    

    return 0;
}