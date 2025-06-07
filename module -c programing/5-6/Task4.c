#include <stdio.h>
#include <conio.h>

void main()
{
    int num1,num2;
    printf("enter number1:- ");
    scanf("%d",&num1);
    printf("\nenter number2:- ");
    scanf("%d",&num2);
    
    if(num1>num2)
    { 
      printf("number1 is big");
    }
    else if (num1,num2==0)
    {
        printf ("both number 0");
    }
    else if (num1==num2)
    {
        printf("both numbers are same");
    }
    else
    {
        printf("number2 is big");
    }
    
    
    
    getch();
}