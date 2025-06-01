/******************************************************************************
3. Write a program to make a square and cube of number.

*******************************************************************************/

#include <stdio.h>
#include <conio.h>

int main()
{
    int a;
    
    
    printf("enter number : ");
    scanf("%d",&a);
    
    int square=a*a;
    printf("\nsquare of %d is = %d",a,square);
    
    int cube=a*a*a;
    printf("\ncube of %d is = %d",a,cube);
    
    


     getch();
}