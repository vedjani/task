
#include<stdio.h>
#include<conio.h>
int main()
{
    int num,one=1;
    
    printf("enter a number :- ");
    scanf("%d",&num);

    if (num<=1)
    {
        one=0;
    }
    else
    {
        for (int i = 2; i < num; i++)
        {
            if (num%i==0)
            {
                printf("this is not prime");
            }
            else
            {
                
                printf("this number is prime");
            }
            
            
        }
        
    }
    
    
    
    
    return 0;
}
