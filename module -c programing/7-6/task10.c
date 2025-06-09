#include<stdio.h>
#include<conio.h>

int main ()
{
  int num;

  printf("enter your num :- ");
  scanf("%d",&num);
  if (num>=10)
  {
    if(num<=50)
     {
    printf("in range");
     }
    // else 
    //  {
    // printf("out of range");
    // }
  }
 else 
  {
    printf("out of range");
  }
  
  
 


  return 0;
}