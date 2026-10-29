#include <iostream>
using namespace std;

long long binomialCoefficient(int n, int k) {
    if(k == 0 || k == n) {
        return 1;
    } else {
        return binomialCoefficient(n-1, k-1) + binomialCoefficient(n-1, k);
    }
}

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    if(k < 0 || k > n) {
        cout << "Error: values must satisfy 0 <= k <= n.\n";
    } else {
        cout << "The binomial coefficient C(" << n << ", " << k << ") is: " << binomialCoefficient(n, k) << "\n";
    }

    return 0;
}