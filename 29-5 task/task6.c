/******************************************************************************
6. Write a program to find the simple Interest.
*******************************************************************************/

#include <stdio.h>
#include <conio.h>

int main()
{
    int p;
    float r;
    int n;
    float intrest,totalamount;
    
    
    printf("enter p : ");
    scanf("%d",&p);
    
    printf("enter r: ");
    scanf("%f",&r);
    
    printf("enter n: ");
    scanf("%d",&n);

    intrest = p*r*n/100;
    
    printf("\n Interest is = %f",intrest);
    totalamount = intrest+p;
    printf("\n Total Amount is = %f",totalamount);
    


     getch();
}