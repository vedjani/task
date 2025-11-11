// Variables and Constants 
// o Write a C++ program that demonstrates the use of variables and constants. Create 
// variables of different data types and perform operations on them. 
// o Objective: Understand the difference between variables and constants.
#include<iostream>
using namespace std;
int main()
{
    const float PI = 3.14;
    int price = 20;
    float height = 5.8;
    char qulity = 'A';
    string name = "tiles";

    cout<<"product name is "<<name<<" and price is "<<price<<" tiles height is "<<height<<endl;
  // float PI=30;//this is not change

   cout<<"pi value is = "<<PI;


    return 0;
}