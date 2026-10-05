#include <iostream>

using namespace std;

int main() {
    int choice = 0;

    cout << "Select a currency conversion option:" << endl;
    cout << "1) Convert to US Dollars (USD)" << endl;
    cout << "2) Convert to British Pounds (GBP)" << endl;
    cout << "3) Convert to Japanese Yen (JPY)" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    cout << endl;

    switch (choice) {
        case 1:
            cout << "Option selected: Conversion to US Dollars (USD)." << endl;
            break;
        case 2:
            cout << "Option selected: Conversion to British Pounds (GBP)." << endl;
            break;
        case 3:
            cout << "Option selected: Conversion to Japanese Yen (JPY)." << endl;
            break;
        default:
            cout << "Invalid option selected. Please choose between 1 and 3." << endl;
    }

    return 0;
}