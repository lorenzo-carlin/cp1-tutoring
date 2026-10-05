#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int val);
void findNextPrime(int start, int &nextPrime, int &gap);

int main() {

    int n = 0;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 1) {
        cout << "Error: Please enter an integer greater than 1." << endl;
        return 0;
    }

    if (isPrime(n)) {
        cout << n << " is a prime number!" << endl;
    } else {
        cout << n << " is NOT a prime number." << endl;
    }

    int nextPrime = 0;
    int gap = 0;
    findNextPrime(n, nextPrime, gap);

    cout << "Next prime: " << nextPrime << endl;
    cout << "Gap (distance): " << gap << endl;

    return 0;
}

bool isPrime(int val) {
    if (val <= 1) return false;
    if (val == 2) return true;

    for(int i = 2; i*i <= val; i++) {
        if(val % i == 0) {
            return false;
        }
    }

    return true;
}

void findNextPrime(int start, int &nextPrime, int &gap) {
    int candidate = start + 1;
    while (!isPrime(candidate)) {
        candidate++;
    }

    nextPrime = candidate;
    gap = nextPrime - start;
}