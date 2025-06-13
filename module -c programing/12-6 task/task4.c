#include<stdio.h>
#include<conio.h>
int main()
{
    int i,i1,ans=1;
    printf("enter a numbre:-");
    scanf("%d",&i1);

    for (i=1;i<=i1;i++)
    { 
        ans=ans*i;
 
    }
    printf("\n%d",ans);
  
    return 0;
}
