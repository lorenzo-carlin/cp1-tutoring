#include <iostream>
#include <string>
using namespace std;

string compress(const string input) {
    string result = "";
    int length = input.length();
    int i = 0;

    while(i < length) {
        int count = 1;

        while(i + count < length && input[i + count] == input[i]) {
            count++;
        }

        result += input[i];

        if(count >= 2) {
            result += to_string(count);
        }

        i += count;
    }

    return result;
}

int main() {
    string text;

    cout << "Enter a string: ";
    getline(cin, text);

    cout << "Compressed string: " << compress(text) << endl;

    return 0;
}
