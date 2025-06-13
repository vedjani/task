#include<stdio.h>
#include<conio.h>
int main()
{
    int num,rem,i1=0;

    printf("enter number :- ");
    scanf("%d",&num);

    while (num>0)
    {
        rem=num%10;
        if (rem>i1)
        {
            i1=rem;
            
        }
         
        num=num/10;
    }
    printf("\n%d is big number",i1);

    
    

    return 0;
}