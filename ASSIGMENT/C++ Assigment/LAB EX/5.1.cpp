#include <iostream>
using namespace std;

int main() {
    int arr[5],sum = 0;

    cout << "Enter " << "5" << " integers:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++) {
        sum += arr[i]; 
    }

    double average = sum / 5;

    cout << "\nSum of array elements = " << sum << endl;
    cout << "Average of array elements = " << average << endl;

    return 0;
}