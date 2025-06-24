#include<stdio.h>
#include<conio.h>
int main()
{
    int i;
    printf("enter number between 1to7:- ");
    scanf("%d",&i);

    switch (i)
    {
    case 1:
        printf("Sunday");
        break;

    case 2:
        printf("Monday");
        break;

    case 3:
        printf("Tuesday");
        break;

    case 4:
        printf("Wednesday");
        break;

    case 5:
        printf("Thursday");
        break;

    case 6:
        printf("Friday");
        break;

    case 7:
        printf("Saturday");
        break;
    
    default:
    printf("enter a valid number");
        break;
    }

    return 0;
}