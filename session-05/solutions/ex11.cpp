#include <iostream>
using namespace std;

const int PRODUCTS = 8;

double calculateInventoryValue(const int stock[], const double prices[], int size) {
    double totalValue = 0.0;
    for(int i = 0; i < size; i++) {
        totalValue += stock[i] * prices[i];
    }
    return totalValue;
}

double processRestock(const int stock[], const double prices[], int size, int threshold, int targetCapacity) {
    double totalRestockCost = 0.0;
    cout << "\nLow Stock Items Alert (Stock < " << threshold << "):" << endl;

    for(int i = 0; i < size; i++) {
        if(stock[i] < threshold) {
            int neededUnits = targetCapacity - stock[i];
            double itemCost = neededUnits * prices[i];
            totalRestockCost += itemCost;

            cout << "- Product " << i << ": " << stock[i] 
                 << " in stock -> Needs " << neededUnits 
                 << " units (Cost: $" << itemCost << ")" << endl;
        }
    }
    return totalRestockCost;
}

int main() {
    int stock[PRODUCTS];
    double prices[PRODUCTS];
    int threshold, targetCapacity;

    cout << "Enter stock quantity for " << PRODUCTS << " products:" << endl;
    for(int i = 0; i < PRODUCTS; i++) {
        cin >> stock[i];
    }
    cout << endl;

    cout << "Enter unit prices ($) for " << PRODUCTS << " products:" << endl;
    for(int i = 0; i < PRODUCTS; i++) {
        cin >> prices[i];
    }
    cout << endl;

    cout << "Enter safety stock threshold: ";
    cin >> threshold;
    cout << "Enter target restock capacity: ";
    cin >> targetCapacity;

    cout << "\n=== INVENTORY REPORT ===" << endl;
    cout << "Total current inventory value: $" << calculateInventoryValue(stock, prices, PRODUCTS) << endl;

    double budgetNeeded = processRestock(stock, prices, PRODUCTS, threshold, targetCapacity);
    cout << "\nTotal Budget Required for Restock: $" << budgetNeeded << endl;

    return 0;
}