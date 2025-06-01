/******************************************************************************
2. Write a program to make addition, Subtraction, Multiplication and Division of
Two Numbers.[User Input]

*******************************************************************************/

#include <stdio.h>
#include <conio.h>

int main()
{
    int a,b;
    
    
    printf("enter a : ");
    scanf("%d",&a);
    
    printf("enter b : ");
    scanf("%d",&b );
    
    int aans =a+b;
    printf("\naddition is =  %d " ,aans);
    
    int sub =a-b;
    printf("\nSubtraction is =  %d",sub);
    
    int mul =a*b;
    printf("\nMultiplication is =  %d",mul);
    
    int Division =a/b;
    printf("\nDivision is =  %d",Division);


     getch();
}