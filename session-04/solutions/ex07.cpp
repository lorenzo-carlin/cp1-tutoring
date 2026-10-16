#include <iostream>
using namespace std;

bool isPerfectNumber(int number, int &sumDivisors);

int main() {
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    if(number <= 0) {
        cout << "\nError: Please enter a positive integer greater than 0." << endl;
        return 1;
    }

    int sumDivisors = 0;
    bool perfect = isPerfectNumber(number, sumDivisors);

    cout << "\nDivisor analysis:" << endl;
    cout << "- Sum of proper divisors: " << sumDivisors << endl;

    if(perfect) {
        cout << "Result: " << number << " IS a perfect number!" << endl;
    } else {
        cout << "Result: " << number << " is NOT a perfect number." << endl;
    }

    return 0;
}

bool isPerfectNumber(int number, int &sumDivisors) {
    sumDivisors = 0;

    for(int i = 1; i <= number / 2; i++) {
        if(number % i == 0) {
            sumDivisors += i;
        }
    }

    return (number == sumDivisors);
}