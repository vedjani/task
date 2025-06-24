#include<stdio.h>
#include<conio.h>
int main()
{
    int i,temp,v;

    printf("how many value you want to enter :- ");
    scanf("%d",&v);

    int num[v];

    for ( i = 0; i < v; i++)
    {
        printf("enter your num:- ");
        scanf("%d",&num[i]);
    }
    temp=num[0];
    for ( i = 0; i < v; i++)
    {
        if (num[i]>temp)
        {
            temp=num[i];
        }
        
    }
    printf("big number is %d",temp);
    
    
    
    
        
        
    
    
    
    return 0;
     
   }
   



  
