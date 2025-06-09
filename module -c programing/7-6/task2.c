#include<stdio.h>
#include<conio.h>
int main()
{
    int age;

    printf("enter your age:- ");
    scanf("%d",&age);

    if (age>=18)
    {
        printf("you eligible for vote");
    }
    else
    {
        printf("you not eligible for vote");
    }
    

    return 0;
}