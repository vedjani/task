#include <iostream>
using namespace std;
class Cal
{
public:
    
    int add(int a, int b)
    {
        return a + b;
    }

   
    int subtract(int a, int b)
    {
        return a - b;
    }

   
    int multiply(int a, int b)
    {
        return a * b;
    }
    float divide(int a, int b)
    {
        return a / b;
    }
};
int main()
{
    Cal calc;    
    float num1, num2;

    cout << "Enter two number1: ";
    cin >> num1;
    cout << "Enter two number2: ";
    cin >> num2;

    cout << "\nAddition: " << calc.add(num1, num2);
    cout << "\nSubtraction: " << calc.subtract(num1, num2);
    cout << "\nMultiplication: " << calc.multiply(num1, num2);
    cout << "\nDivision: " << calc.divide(num1, num2);

    return 0;
}
