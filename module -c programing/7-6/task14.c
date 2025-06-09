#include<stdio.h>
#include<conio.h>
int main()
{
 float temp;

 printf("enter temperature:- ");
 scanf("%f",&temp);

 if (temp<-1.00) 
 {
    printf("its very cold");
 }
 else if (temp<45.00)
 {
    printf("its warm");
 }
 else
 {
    printf("its very hot");
 }
 

return 0;
}