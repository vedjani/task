#include<iostream>
using namespace std; 
int global_v=100;
void fun()
{
    int local_v=10;
    cout<<"fun()"<<endl;
    cout<<"local var is ="<<local_v<<endl;
    cout<<"global var is ="<<global_v<<endl;
    printf("\n");
}
int main()
{
    int local_v=20;
    cout<<endl<<"main()"<<endl;
    cout<<"local var is ="<<local_v<<endl;
    cout<<"global var is ="<<global_v<<endl<<endl;

    fun();
    return 0;
}