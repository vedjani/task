#include<stdio.h>
#include<conio.h>
int main()
{
   int marks[6],i,total=0,m1;
 
   for (i=0;i<6;i++)
   {
    printf("enter your marks:- ");
    scanf("%d",&marks[i]);
   }
   for (i=0;i<6;i++)
   {
     total+=marks[i];
     
   }
   printf("total = %d",total);
   m1 = total/6;
   printf("\nYour Percentage is %d",m1);
   


    return 0;
}