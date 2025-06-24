#include<stdio.h>
#include<conio.h>
int main()
{
    int num ,fir=0,sec=1,nex;

    printf("enter num:- ");
    scanf("%d",&num);
    printf("Fibonacci Series: %d %d ", fir, sec);

    for (int i=2;i<num;i++)
    {
        nex=fir+sec;
        printf("%d ",nex );
        fir=sec;
        sec=nex;
        
    }

    




    return 0;
}