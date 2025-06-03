/******************************************************************************

 7. Write a program to calculate sum of 5 subjects & find the percentage.
Subject marks entered by user.

*******************************************************************************/

#include <stdio.h>
#include <conio.h>
int main()
{
    int guj;
    int eng;
    int sci;
    int math;
    int hin;
    float total;
    float pr;
    
    printf("enter gujrati marks:-");
    scanf("%d",&guj);
    
    printf("enter English marks:-");
    scanf("%d",&eng);
    
    printf("enter science marks:-");
    scanf("%d",&sci);
    
    printf("enter maths marks:-");
    scanf("%d",&math);
    
    printf("enter hindi marks:-");
    scanf("%d",&hin);
    
    total=guj+eng+sci+math+hin;
    
    printf("\ntotal = %f",total);
    
    pr= (total / 500) * 100;
    printf("\nyour percetange is :- %f",pr);
    
    getch();
}