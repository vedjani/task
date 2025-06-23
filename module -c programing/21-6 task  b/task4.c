#include<stdio.h>
#include<conio.h>
int main()
{
  int j,k,i;

  for ( i = 1; i <=5; i++)
  {
    for ( j = 1; j <=(5-i); j++)
    {
       printf(" ");
    }
    for (k=0;k<=i;k++)
    {
        printf("%d",i);
        
    }
    printf("\n");
    
    
  }
  


    return 0;
}