#include<stdio.h>
#include<conio.h>

int main ()
{
  int age;

  printf("enter your age :- ");
  scanf("%d",&age);
  if (age<=18)
  {
    printf("your ticket price is 50");
  }
  else if(age<=40)
  {
    printf("your ticket price is 100");
  }
  else 
  {
    printf("your ticket price is 150");
  }
 


  return 0;
}