#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int number, int k);

int main() {
    int k;

    cout << "Enter number of digits k (3-7): ";
    cin >> k;

    if(k < 3 || k > 7) {
        cout << "\nError: k must be an integer between 3 and 7." << endl;
        return 1;
    }

    cout << "\nSearching for " << k << "-digit Armstrong numbers..." << endl;

    int start = pow(10, k - 1);
    int end = pow(10, k) - 1;

    int count = 0;
    for(int i = start; i <= end; i++) {
        
        if(isArmstrong(i, k)) {
            cout << "- Found: " << i << endl;
            count++;
        }
    }

    cout << "\nTotal " << k << "-digit Armstrong numbers found: " << count << endl;

    return 0;
}

bool isArmstrong(int number, int k) {
    int temp = number;
    int sumOfPowers = 0;

    while(temp > 0) {
        int digit = temp % 10;
        sumOfPowers += pow(digit, k);
        temp /= 10;
    }

    return (number == sumOfPowers);
}