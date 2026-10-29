#include <iostream>
using namespace std;

int gcd(int m, int n) {
    if(n == 0) {
        return m;
    } else {
        return gcd(n, m % n);
    }
}

int main() {
    int m, n;
    cout << "Enter two positive integers (m n): ";
    cin >> m >> n;
    if(m > 0 && n > 0) {
        int result = gcd(m, n);
        cout << "The GCD of " << m << " and " << n << " is: " << result << "\n";
    } else {
        cout << "Invalid input! Please make sure to enter two positive integers (> 0).\n";
    }

    return 0;
}