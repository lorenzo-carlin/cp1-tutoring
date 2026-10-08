#include <iostream>
using namespace std;

int main() {
    const double RATE_USD = 1.08;
    const double RATE_GBP = 0.85;
    const double RATE_JPY = 162.5;

    double euros = 0.0;

    cout << "=== Multi-Currency Kiosk ===" << endl;
    cout << "Enter your current balance in Euros: ";
    cin >> euros;

    if (euros < 0) {
        cout << endl << "Error: Balance cannot be negative." << endl;
    } else {

        cout << endl;
        cout << "Select target currency:" << endl;
        cout << "1) US Dollars (USD)" << endl;
        cout << "2) British Pounds (GBP)" << endl;
        cout << "3) Japanese Yen (JPY)" << endl;
        cout << "Enter choice (1-3): ";

        int choice = 0;
        cin >> choice;

        cout << endl;

        if (choice < 1 || choice > 3) {
            cout << "Error: Invalid option selected." << endl;
        } else {

            streamsize default_precision = cout.precision();

            cout << fixed;
            cout.precision(2);

            switch (choice) {
                case 1:
                    cout << euros << " EUR = " << (euros * RATE_USD) << " USD" << endl;
                    break;
                case 2:
                    cout << euros << " EUR = " << (euros * RATE_GBP) << " GBP" << endl;
                    break;
                case 3:
                    cout << euros << " EUR = " << (euros * RATE_JPY) << " JPY" << endl;
                    break;
            }

            cout.precision(default_precision);
            cout << defaultfloat;
        }
    }

    return 0;
}