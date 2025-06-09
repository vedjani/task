#include <stdio.h>
#include <conio.h>

void main()
{
    int num1,num2,temp;
    
    printf("enter number 1 :- ");
    scanf("%d",&num1);
    printf("\nenter number 2 :- ");
    scanf("%d",&num2);
    
    num1=num1+num2;
    num2=num1-num2;
    num1=num1-num2;
    
    printf("\nafter exchage");
    printf("\nnumber 1 is %d",num1);
    printf("\nnumber 2 is %d",num2);
    
    
    
     getch();
}