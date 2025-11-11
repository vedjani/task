#include<iostream>
using namespace std;
int add(int a,int b)
{
    cout<<"sum of num1 & num2 is "<<a+b<<endl;
    return 0;
}
int sub(int a,int b)
{
    cout<<"subtract of num1 & num2 is "<<a-b<<endl;
    return 0;
}
int mul(int a,int b)
{
    cout<<"multiply of num1 & num2 is "<<a*b<<endl;
    return 0;
}
int divi(int a,int b)
{
    cout<<"divide of num1 & num2 is "<<a/b<<endl;
    return 0;
}
int main()
{
    int num1,num2;
    cout<<"Enter num 1:-";
    cin>>num1;
    cout<<"Enter num 2:-";
    cin>>num2;
    add(num1,num2);
    sub(num1,num2);
    mul(num1,num2);
    divi(num1,num2);
    
    return 0;
}