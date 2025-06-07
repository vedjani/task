#include <stdio.h>
#include <conio.h>

void main()
{
    int num;
    printf("enter number:-");
    scanf("%d",&num);
    
    if(num>0)
    { 
      printf("positive number");
    }
    else if(num==0)
    {
        printf("zero");
    }
    else
    {
        printf("negative number");
    }
    
    
    
    getch();
}