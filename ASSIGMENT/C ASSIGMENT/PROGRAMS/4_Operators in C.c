#include<stdio.h>
#include<conio.h>
int main()
{
    int num1,num2,ans;
    printf("enter a number :- ");
    scanf("%d",&num1);
    printf("enter a number :- ");
    scanf("%d",&num2);
    ans==0;
    ans=num1+num2;
    printf("sum of two number is :- %d",ans);


    if(num1>100 && num2>100)
    {
    printf("\n both numbers are bigger than 100 ");
    }
    else
    {
        printf("\n both numbers not bigger than 100");
    }
    

    return 0;
}