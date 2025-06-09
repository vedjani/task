#include<stdio.h>
#include<conio.h>

void main ()
{
  int year;

  printf("enter your marks :- ");
  scanf("%d",&year);
  if (year%400==0)
  {
    printf("its leap year");
  }
  else if (year%100==0)
  {
     printf("its not leap year");
  }
  else if (year%4==0)
  {
    printf("its leap year");
  }
  else
  {
    printf("its not leap year");
  }


    getch();
}
