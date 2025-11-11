#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter Row Number:- ";
    cin>>num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    

    return 0;
}