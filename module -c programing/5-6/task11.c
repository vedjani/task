#include<stdio.h>
#include<conio.h>

void main()
{
    
    int year,bonus,salary;
    
    printf ("enter your salary:-");
    scanf ("%d",&salary);
    printf ("\nenter your years of service:-");
    scanf ("%d",&year);

    if (year >= 5)
    { 
        printf("your bonus is 5500");
        printf("\nyour total salary is %d",salary+5500);
    }

    else if (year >= 4)
    {
        printf ("your bonus is 4500");
        printf("\nyour total salary is %d",salary+4500);
    }
    
    else if (year >= 3)
    {
        printf("your bonus is 3500");
        printf("\nyour total salary is %d",salary+3500);
    }
    
    else
    {
        printf("your bonus is 2500");
        printf("\nyour total salary is %d",salary+2500);
    }
    
    
    getch();
}