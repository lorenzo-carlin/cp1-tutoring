#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_PRODUCTS = 100;

struct Product {
    string name;
    int quantity;
    double unitPrice;
};

int loadInventory(const string& fileName, Product items[], int maxItems) {
    ifstream input(fileName);

    if(!input.is_open()) {
        return -1;
    }

    int count;
    input >> count;

    if(!input || count <= 0 || count > maxItems) {
        return -1;
    }

    for(int i = 0; i < count; i++) {
        input >> items[i].name >> items[i].quantity >> items[i].unitPrice;

        if(!input) {
            return -1;
        }
    }

    input.close();

    return count;
}

int findProduct(const Product items[], int count, const string& name) {
    for(int i = 0; i < count; i++) {
        if(items[i].name == name) {
            return i;
        }
    }

    return -1;
}

void printInventory(const Product items[], int count) {
    ios::fmtflags oldFlags = cout.flags();
    streamsize oldPrecision = cout.precision();

    cout << fixed << setprecision(2);
    cout << "=== INVENTORY ===" << endl;

    double total = 0;

    for(int i = 0; i < count; i++) {
        cout << i + 1 << ". " << left << setw(12) << items[i].name
             << right << " Qty: " << setw(4) << items[i].quantity
             << "  Price: " << items[i].unitPrice << " EUR" << endl;

        total += items[i].quantity * items[i].unitPrice;
    }

    cout << "Total inventory value: " << total << " EUR" << endl;

    cout.flags(oldFlags);
    cout.precision(oldPrecision);
}

bool sellProduct(Product items[], int count, const string& name, int quantity) {
    if(quantity <= 0) {
        return false;
    }

    int index = findProduct(items, count, name);

    if(index == -1 || items[index].quantity < quantity) {
        return false;
    }

    items[index].quantity -= quantity;

    return true;
}

bool restockProduct(Product items[], int count, const string& name, int quantity) {
    if(quantity <= 0) {
        return false;
    }

    int index = findProduct(items, count, name);

    if(index == -1) {
        return false;
    }

    items[index].quantity += quantity;

    return true;
}

bool saveInventory(const string& fileName, const Product items[], int count) {
    ofstream output(fileName);

    if(!output.is_open()) {
        return false;
    }

    output << count << endl;

    for(int i = 0; i < count; i++) {
        output << items[i].name << " " << items[i].quantity << " "
               << fixed << setprecision(2) << items[i].unitPrice << endl;
    }

    output.close();

    return true;
}

int main() {
    string fileName;

    cout << "Enter inventory file name: ";
    cin >> fileName;

    Product items[MAX_PRODUCTS];
    int count = loadInventory(fileName, items, MAX_PRODUCTS);

    if(count < 0) {
        cout << "Error: could not load a valid inventory from \"" << fileName << "\"." << endl;
        return 1;
    }

    int choice;

    do {
        cout << "\n=== INVENTORY MANAGER ===" << endl;
        cout << "1) Show inventory" << endl;
        cout << "2) Sell product" << endl;
        cout << "3) Restock product" << endl;
        cout << "4) Save and exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << endl;
            printInventory(items, count);
        } else if(choice == 2) {
            string name;
            int quantity;

            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter quantity to sell: ";
            cin >> quantity;

            int index = findProduct(items, count, name);

            if(index == -1) {
                cout << "Error: product \"" << name << "\" not found." << endl;
            } else if(quantity <= 0) {
                cout << "Error: quantity must be positive." << endl;
            } else if(!sellProduct(items, count, name, quantity)) {
                cout << "Error: insufficient stock for " << name
                     << " (available: " << items[index].quantity << ")." << endl;
            } else {
                cout << "\nSold " << quantity << " x " << name
                     << ". New stock: " << items[index].quantity << endl;
            }
        } else if(choice == 3) {
            string name;
            int quantity;

            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter quantity to add: ";
            cin >> quantity;

            int index = findProduct(items, count, name);

            if(index == -1) {
                cout << "Error: product \"" << name << "\" not found." << endl;
            } else if(quantity <= 0) {
                cout << "Error: quantity must be positive." << endl;
            } else {
                restockProduct(items, count, name, quantity);
                cout << "\nRestocked " << quantity << " x " << name
                     << ". New stock: " << items[index].quantity << endl;
            }
        } else if(choice == 4) {
            if(saveInventory(fileName, items, count)) {
                cout << "\nInventory saved to " << fileName << ". Goodbye!" << endl;
            } else {
                cout << "Error: could not save inventory to \"" << fileName << "\"." << endl;
                return 1;
            }
        } else {
            cout << "Error: invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while(choice != 4);

    return 0;
}
