#include<stdio.h>
#include<conio.h>
int main()
{
    int num,count=0;

    printf("enter number :- ");
    scanf("%d",&num);

    for (int i=1;i<=num;i++)
    {
        if (num%i==0)
        {
            count++;
        }

    }
    if (count>2)
    {
        printf("not prime");
    }
    else
    {
        printf("prime");
    }
    
    
    
    
    
    
    return 0;
}
