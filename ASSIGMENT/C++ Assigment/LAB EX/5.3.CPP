#include<iostream>
using namespace std;

int main()
{
    string str;
    int length = 0;

    cout << "enter a string : ";
    cin >> str;

   
    while (str[length] != '\0')
    {
        length++;
    }

    int i = 0;
    int j = length - 1;

   
    while (i < j)
    {
        if (str[i] != str[j])
        {
            cout << "\nnot palindrome";   
            return 0;                    
        }
        i++;
        j--;
    }

    cout << "\npalindrome";  

    return 0;
}
