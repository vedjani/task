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
    for (k=1;k<=i;k++)
    {
        printf("%d",k);
        
    }
    printf("\n");
    
    
  }
  


    return 0;
}