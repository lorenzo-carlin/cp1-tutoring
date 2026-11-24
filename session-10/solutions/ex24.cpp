#include <iostream>
#include <string>
using namespace std;

struct RunNode {
    char value;
    int count;
    RunNode* next;
};

RunNode* buildList(const string& text) {
    RunNode* head = nullptr;
    RunNode* tail = nullptr;

    for(int i = 0; i < (int)text.length(); i++) {
        RunNode* node = new RunNode;
        node->value = text[i];
        node->count = 1;
        node->next = nullptr;

        if(tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }

        tail = node;
    }

    return head;
}

void compress(RunNode*& head) {
    if(head == nullptr) {
        return;
    }

    RunNode* runStart = head;
    RunNode* current = head->next;

    while(current != nullptr) {
        if(current->value == runStart->value) {
            runStart->count += current->count;

            RunNode* node = current;
            current = current->next;
            runStart->next = current;
            delete node;
        } else {
            runStart = current;
            current = current->next;
        }
    }
}

void expand(RunNode*& head) {
    RunNode* current = head;

    while(current != nullptr) {
        int copies = current->count;
        current->count = 1;

        RunNode* runEnd = current;

        for(int i = 1; i < copies; i++) {
            RunNode* node = new RunNode;
            node->value = current->value;
            node->count = 1;
            node->next = runEnd->next;

            runEnd->next = node;
            runEnd = node;
        }

        current = runEnd->next;
    }
}

void printCompact(const RunNode* head) {
    for(const RunNode* current = head; current != nullptr; current = current->next) {
        cout << current->value << "(" << current->count << ")";
    }
}

void printText(const RunNode* head) {
    for(const RunNode* current = head; current != nullptr; current = current->next) {
        for(int i = 0; i < current->count; i++) {
            cout << current->value;
        }
    }
}

int nodeCount(const RunNode* head) {
    int count = 0;

    for(const RunNode* current = head; current != nullptr; current = current->next) {
        count++;
    }

    return count;
}

void destroyList(RunNode*& head) {
    while(head != nullptr) {
        RunNode* node = head;
        head = head->next;
        delete node;
    }
}

int main() {
    string text;

    cout << "Enter text: ";
    getline(cin, text);

    RunNode* head = buildList(text);

    int nodes = nodeCount(head);

    cout << "\nOriginal text: ";
    printText(head);
    cout << " (" << nodes << (nodes == 1 ? " node)" : " nodes)") << endl;

    compress(head);
    nodes = nodeCount(head);

    cout << "Compact list:  ";
    printCompact(head);
    cout << " (" << nodes << (nodes == 1 ? " node)" : " nodes)") << endl;

    expand(head);
    nodes = nodeCount(head);

    cout << "Expanded text: ";
    printText(head);
    cout << " (" << nodes << (nodes == 1 ? " node)" : " nodes)") << endl;

    destroyList(head);

    return 0;
}
