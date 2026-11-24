#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ReadingNode {
    int value;
    int index;
    ReadingNode* next;
};

struct Window {
    ReadingNode* head;
    ReadingNode* tail;
    int size;
};

void initWindow(Window& window) {
    window.head = nullptr;
    window.tail = nullptr;
    window.size = 0;
}

void pushReading(Window& window, int value, int index, int capacity) {
    while(window.size >= capacity && window.head != nullptr) {
        ReadingNode* node = window.head;
        window.head = node->next;
        delete node;
        window.size--;

        if(window.head == nullptr) {
            window.tail = nullptr;
        }
    }

    ReadingNode* node = new ReadingNode;
    node->value = value;
    node->index = index;
    node->next = nullptr;

    if(window.tail == nullptr) {
        window.head = node;
    } else {
        window.tail->next = node;
    }

    window.tail = node;
    window.size++;
}

int windowSpan(const Window& window) {
    if(window.head == nullptr || window.tail == nullptr) {
        return 0;
    }

    return window.tail->value - window.head->value;
}

void printWindow(const Window& window) {
    for(const ReadingNode* current = window.head; current != nullptr; current = current->next) {
        cout << current->value;

        if(current->next != nullptr) {
            cout << " ";
        }
    }

    cout << endl;
}

void destroyWindow(Window& window) {
    while(window.head != nullptr) {
        ReadingNode* node = window.head;
        window.head = node->next;
        delete node;
    }

    window.tail = nullptr;
    window.size = 0;
}

bool monitorFile(const string& fileName, int capacity, int threshold) {
    if(capacity <= 0) {
        return false;
    }

    ifstream input(fileName);

    if(!input.is_open()) {
        return false;
    }

    Window window;
    initWindow(window);

    int value;
    int index = 0;

    while(input >> value) {
        index++;

        pushReading(window, value, index, capacity);

        if(window.size == capacity) {
            int span = windowSpan(window);
            int spanAbs = span >= 0 ? span : -span;

            cout << "Reading #" << index << " (" << value << "):  window [";

            for(const ReadingNode* current = window.head; current != nullptr; current = current->next) {
                cout << current->value;

                if(current->next != nullptr) {
                    cout << ", ";
                }
            }

            cout << "], span ";

            if(span >= 0) {
                cout << "+";
            }

            cout << span;

            if(spanAbs >= threshold) {
                cout << " -> ALERT at #" << index << ": oldest " << window.head->value
                     << ", newest " << window.tail->value << ", span ";

                if(span >= 0) {
                    cout << "+";
                }

                cout << span;
            }

            cout << endl;
        }
    }

    cout << "\nFinal window (" << window.size << " readings): ";
    printWindow(window);

    destroyWindow(window);
    input.close();

    return true;
}

int main() {
    string fileName;
    int capacity;
    int threshold;

    cout << "Enter file name: ";
    cin >> fileName;

    cout << "Enter window size K: ";
    cin >> capacity;

    cout << "Enter alert threshold: ";
    cin >> threshold;

    if(capacity <= 0) {
        cout << "\nError: K must be positive." << endl;
        return 1;
    }

    if(!monitorFile(fileName, capacity, threshold)) {
        cout << "\nError: could not open file \"" << fileName << "\"." << endl;
        return 1;
    }

    return 0;
}
