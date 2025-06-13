#include<stdio.h>
#include<conio.h>
int main()
{
    int num,rem,i1=9;

    printf("enter number :- ");
    scanf("%d",&num);

    while (num>0)
    {
        rem=num%10;
        if (rem<i1)
        {
            i1=rem;
            
        }
         
        num=num/10;
    }
    printf("\n%d is small number",i1);

    
    

    return 0;
}