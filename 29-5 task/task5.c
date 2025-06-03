/******************************************************************************
5. Write a program to find the Area of Triangle
*******************************************************************************/

#include <stdio.h>
#include <conio.h>

int main()
{
    float b;
    float h;
    float ans;
    
    
    printf("enter base : ");
    scanf("%f",&b);
    printf("enter height: ");
    scanf("%f",&h);
    ans=(b*h)/2;
    printf("Area Of Triangle is = %f",ans);
    
    
    


     getch();
}