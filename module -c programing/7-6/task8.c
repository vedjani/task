#include<stdio.h>
#include<conio.h>

int main ()
{
  int num;

  printf("enter your number :- ");
  scanf("%d",&num);
  if (num%3==0 && num%5==0)
  {
    printf("its divide by 3 and 5");
  }
  else
  {
    printf("its not divide by 3 and 5");
  }
 


    getch();
}