
#include <iostream>
using namespace std;
 
int main()
{
	int a[2][2], b[2][2], sum[2][2];
 
	cout << "\nEnter elements of A matrix : "<<endl;
	for (int i = 0; i < 2; i++)
	{
    	for (int j = 0; j < 2; j++)
    	{
            cout << "A[" << i << "][" << j << "] = ";
        	cin >> a[i][j];
    	}
	}
 
	cout << "\nEnter elements of B matrix : "<<endl;
	for (int i = 0; i < 2; i++)
	{
    	for (int j = 0; j < 2; j++)
    	{
            cout << "B[" << i << "][" << j << "] = ";
        	cin >> b[i][j];
    	}
	}
 
	for (int i = 0; i < 2; i++)
	{
    	for (int j = 0; j < 2; j++)
    	{
        	sum[i][j] = a[i][j] + b[i][j];
    	}
	}
	cout << "\nSum of the A & B matrix is : "<<endl;
	for (int i = 0; i < 2; i++)
	{
    	for (int j = 0; j < 2; j++)
    	{
           cout << "SUM[" << i << "][" << j << "] = ";
    	   cout << sum[i][j] <<endl;
    	}
    	//cout << endl;
	}
	return 0;
}