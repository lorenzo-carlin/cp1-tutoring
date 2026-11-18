#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct FileStats {
    int totalLines;
    int emptyLines;
    int words;
    int characters;
    string longestLine;
    int longestLineNumber;
};

bool analyzeFile(const string& fileName, FileStats& stats) {
    ifstream input(fileName);

    if(!input.is_open()) {
        return false;
    }

    stats.totalLines = 0;
    stats.emptyLines = 0;
    stats.words = 0;
    stats.characters = 0;
    stats.longestLine = "";
    stats.longestLineNumber = 0;

    string line;

    while(getline(input, line)) {
        stats.totalLines++;
        stats.characters += (int)line.length();

        if(line.empty()) {
            stats.emptyLines++;
        }

        bool inWord = false;

        for(int i = 0; i < (int)line.length(); i++) {
            if(line[i] != ' ') {
                if(!inWord) {
                    stats.words++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }

        if((int)line.length() > (int)stats.longestLine.length()) {
            stats.longestLine = line;
            stats.longestLineNumber = stats.totalLines;
        }
    }

    input.close();

    return true;
}

int main() {
    string fileName;

    cout << "Enter file name: ";
    cin >> fileName;

    FileStats stats;

    if(!analyzeFile(fileName, stats)) {
        cout << "Error: could not open file \"" << fileName << "\"." << endl;
        return 1;
    }

    cout << "\n=== FILE REPORT ===" << endl;
    cout << "Total lines: " << stats.totalLines << endl;
    cout << "Empty lines: " << stats.emptyLines << endl;
    cout << "Total words: " << stats.words << endl;
    cout << "Total characters: " << stats.characters << endl;
    cout << "Longest line: #" << stats.longestLineNumber
         << " (" << (int)stats.longestLine.length() << " characters)" << endl;
    cout << "> " << stats.longestLine << endl;

    return 0;
}
