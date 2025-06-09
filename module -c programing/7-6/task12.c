#include<stdio.h>
#include<conio.h>

int main()
{
    int num1,num2,num3;

    printf("enter number 1:- ");
    scanf("%d",&num1);
    printf("enter number 2:- ");
    scanf("%d",&num2);
    printf("enter number 3:-");
    scanf("%d",&num3);

    if (num1>num2)
    {
        if (num1>num3)
        {
            printf("number 1 is big ");
        }
        else
        {
            printf("number 3 is big ");
        }
    }
    else if (num2>num3)
    {
        printf("number 2 is big ");
    }
    else
    {
        printf("number 3 is big ");
    }
    
return 0;
}