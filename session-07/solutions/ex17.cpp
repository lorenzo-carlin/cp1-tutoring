#include <iostream>
using namespace std;

void sortCharArray(char arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != i) {
            char temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

bool areAnagrams(const char arr1[], const char arr2[], int size) {
    char* copy1 = new char[size];
    char* copy2 = new char[size];

    for(int i = 0; i < size; i++) {
        copy1[i] = arr1[i];
        copy2[i] = arr2[i];
    }

    sortCharArray(copy1, size);
    sortCharArray(copy2, size);

    bool anagrams = true;

    for(int i = 0; i < size; i++) {
        if(copy1[i] != copy2[i]) {
            anagrams = false;
            break;
        }
    }

    delete[] copy1;
    delete[] copy2;

    return anagrams;
}

void printCharArray(const char arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i];

        if(i < size - 1) {
            cout << " ";
        }
    }

    cout << endl;
}

int main() {
    int size;

    cout << "Enter array length N: ";
    cin >> size;

    if(size <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    char* array1 = new char[size];
    char* array2 = new char[size];

    cout << "Enter characters for Array 1: ";
    for(int i = 0; i < size; i++) {
        cin >> array1[i];
    }

    cout << "Enter characters for Array 2: ";
    for(int i = 0; i < size; i++) {
        cin >> array2[i];
    }

    char* sorted1 = new char[size];
    char* sorted2 = new char[size];

    for(int i = 0; i < size; i++) {
        sorted1[i] = array1[i];
        sorted2[i] = array2[i];
    }

    sortCharArray(sorted1, size);
    sortCharArray(sorted2, size);

    cout << "\nSorted Array 1: ";
    printCharArray(sorted1, size);
    cout << "Sorted Array 2: ";
    printCharArray(sorted2, size);
    cout << endl;

    if(areAnagrams(array1, array2, size)) {
        cout << "Result: The input sequences are ANAGRAMS!" << endl;
    } else {
        cout << "Result: The input sequences are NOT anagrams." << endl;
    }

    delete[] array1;
    delete[] array2;
    delete[] sorted1;
    delete[] sorted2;

    return 0;
}
