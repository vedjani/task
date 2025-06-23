#include<stdio.h>
#include<conio.h>
int main()
{
    float num1,num2,ans,pi=3.14;
    int i;
    printf("enter number 1 for Triangle \n enter number 2 for Rectangle   \n enter number 3 for Circle  \n  enter number :- ");
    scanf("%d",&i);    


    switch (i)
    {
    case 1:
      printf("enter base :- ");
      scanf("%f",&num1);
      printf("enter height :- ");
      scanf("%f",&num2);
      ans=0.5*num1*num2;
      printf("Area Of Triangle = %f",ans);
      break;
   

    case 2:
      printf("enter Breadth :- ");
      scanf("%f",&num1);
      printf("enter Length :- ");
      scanf("%f",&num2);
      ans=num1*num2;
      printf("Area Of Rectangle = %f",ans);
      break;

    case 3:
      printf("enter Raidus : ");
      scanf("%f",&num1);
      ans=pi*num1*num1;
      printf("Area Of Circl is = %f",ans);
      break;

    
    default:
    printf("enter a valid number");
        break;
    }

    return 0;
}