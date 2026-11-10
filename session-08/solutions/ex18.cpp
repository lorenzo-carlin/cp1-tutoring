#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string toTitleCase(const string text) {
    string result = text;
    bool newWord = true;

    for(int i = 0; i < (int)result.length(); i++) {
        char c = result[i];

        if(c == ' ') {
            newWord = true;
        } else if(newWord) {
            result[i] = toupper((unsigned char)c);
            newWord = false;
        } else {
            result[i] = tolower((unsigned char)c);
        }
    }

    return result;
}

int main() {
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    cout << "Formatted sentence: " << toTitleCase(sentence) << endl;

    return 0;
}
