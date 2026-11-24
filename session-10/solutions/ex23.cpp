#include <iostream>
using namespace std;

struct CharNode {
    char value;
    CharNode* next;
};

void initLine(CharNode*& head, CharNode*& cursor) {
    head = new CharNode;
    head->value = '\0';
    head->next = nullptr;

    cursor = head;
}

bool moveLeft(CharNode* head, CharNode*& cursor) {
    if(cursor == head) {
        return false;
    }

    CharNode* previous = head;

    while(previous->next != cursor) {
        previous = previous->next;
    }

    cursor = previous;
    return true;
}

bool moveRight(CharNode*& cursor) {
    if(cursor->next == nullptr) {
        return false;
    }

    cursor = cursor->next;
    return true;
}

void insertChar(CharNode*& head, CharNode*& cursor, char c) {
    CharNode* node = new CharNode;
    node->value = c;
    node->next = cursor->next;

    cursor->next = node;
    cursor = node;
}

bool backspace(CharNode*& head, CharNode*& cursor) {
    if(cursor == head) {
        return false;
    }

    CharNode* previous = head;

    while(previous->next != cursor) {
        previous = previous->next;
    }

    previous->next = cursor->next;
    delete cursor;
    cursor = previous;

    return true;
}

bool deleteChar(CharNode*& cursor) {
    if(cursor->next == nullptr) {
        return false;
    }

    CharNode* node = cursor->next;
    cursor->next = node->next;
    delete node;

    return true;
}

void printLine(const CharNode* head, const CharNode* cursor) {
    cout << "Text: ";

    for(const CharNode* current = head->next; current != nullptr; current = current->next) {
        if(current == cursor->next) {
            cout << '|';
        }

        cout << current->value;
    }

    if(cursor->next == nullptr) {
        cout << '|';
    }

    cout << endl;
}

void destroyLine(CharNode*& head) {
    while(head != nullptr) {
        CharNode* node = head;
        head = head->next;
        delete node;
    }
}

int main() {
    CharNode* head;
    CharNode* cursor;

    initLine(head, cursor);

    int choice;

    do {
        cout << "\n=== CURSOR EDITOR ===" << endl;
        cout << "1) Move cursor left" << endl;
        cout << "2) Move cursor right" << endl;
        cout << "3) Insert character" << endl;
        cout << "4) Backspace" << endl;
        cout << "5) Delete character" << endl;
        cout << "6) Print line" << endl;
        cout << "7) Quit" << endl;
        cout << "> ";
        cin >> choice;

        if(choice == 1) {
            if(!moveLeft(head, cursor)) {
                cout << "Error: cursor is already at the beginning." << endl;
            }

            printLine(head, cursor);
        } else if(choice == 2) {
            if(!moveRight(cursor)) {
                cout << "Error: no character after the cursor." << endl;
            }

            printLine(head, cursor);
        } else if(choice == 3) {
            char c;

            cout << "Character: ";
            cin >> c;

            insertChar(head, cursor, c);
            printLine(head, cursor);
        } else if(choice == 4) {
            if(!backspace(head, cursor)) {
                cout << "Error: cursor is already at the beginning." << endl;
            }

            printLine(head, cursor);
        } else if(choice == 5) {
            if(!deleteChar(cursor)) {
                cout << "Error: no character after the cursor." << endl;
            }

            printLine(head, cursor);
        } else if(choice == 6) {
            printLine(head, cursor);
        } else if(choice == 7) {
            cout << "Bye!" << endl;
        } else {
            cout << "Error: invalid choice." << endl;
        }
    } while(choice != 7);

    destroyLine(head);
    cursor = nullptr;

    return 0;
}
