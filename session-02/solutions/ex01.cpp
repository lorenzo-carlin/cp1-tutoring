#include <iostream>
using namespace std;

int main() {
    const double EXCHANGE_RATE = 1.08;
    double euros = 0.0;

    cout << "Enter capital in Euros: ";
    cin >> euros;

    double usd = euros * EXCHANGE_RATE;
    streamsize default_precision = cout.precision();

    cout << fixed;
    cout.precision(2);
    cout << euros << " EUR is equivalent to " << usd << " USD" << endl;

    cout.precision(default_precision);
    cout << defaultfloat;

    return 0;
}