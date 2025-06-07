#include <stdio.h>
#include <conio.h>

void main()
{
    int num1,num2,num3;
    
    printf("enter number 1 :- ");
    scanf("%d",&num1);
    printf("\nenter number 2 :- ");
    scanf("%d",&num2);
    printf("\nenter number 3 :- ");
    scanf("%d",&num3);
    
    if(num1>num2)
    {
        if (num1>num3)
        {
            printf("\nnumber 1 is big");
        }
         else
         {
            printf("\nnumber 3 is big");
         }
    }
    else
    {
      if(num2>num3)
      {
         printf("\nnumbet 2 is big");
      }
      else
      {
          printf("\nnumber 3 is big");
      }
    }
    
    
    
     getch();
}