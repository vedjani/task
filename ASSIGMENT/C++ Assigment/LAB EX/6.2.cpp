#include <iostream>
using namespace std;
class bank_acc
{
private:
    int balance;

public:
    void main_bal(int b)
    {
        balance = b;
    }

    void deposit(int amount)
    {
        balance = balance + amount;
    }

    void withdraw(int amount)
    {
        if (amount <= balance)
            balance = balance - amount;
        else
            cout << "\nu dont have that much amount to withdraw";
    }

    int final_bal()
    {
        return balance;
    }
};
int main()
{
    bank_acc acc;
    int num;
    int dep;
    acc.main_bal(1000);
    cout << "your balance is :- 1000" << endl;
    cout << "1.deposit" << endl
         << "2.withdraw" << endl
         << "enter choice:- ";
    cin >> num;

    switch (num)
    {
    case 1:
        cout << "enter deposit amount:-";
        cin >> dep;
        acc.deposit(dep);
        break;
    case 2:
        cout << "enter withdraw amount:-";
        cin >> dep;
        acc.withdraw(dep);
        break;
    default:
        cout << "selete 1 or 2";
        break;
    }
    cout << "\nFinal balance : " << acc.final_bal();
    return 0;
}