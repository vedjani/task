#include<stdio.h>
#include<conio.h>
int main()
{
    int num1,num2,i,ans;
     printf("enter number 1 for Addition \n enter number 2 for Subtraction  \n enter number 3 for Multiplication  \n enter number 4 for Division  \n enter number :- ");
    scanf("%d",&i);
    printf("enter number1:- ");
    scanf("%d",&num1);
    printf("enter number2:- ");
    scanf("%d",&num2);
   

    switch (i)
    {
    case 1:
        ans=num1+num2;
        printf("your ans is %d",ans);
        break;

    case 2:
        ans=num1-num2;
        printf("your ans is %d",ans);
        break;

    case 3:
        ans=num1*num2;
        printf("your ans is %d",ans);
        break;

    case 4:
        ans=num1%num2;
        printf("your ans is %d",ans);
        break;
    
    default:
    printf("enter a valid number");
        break;
    }

    return 0;
}