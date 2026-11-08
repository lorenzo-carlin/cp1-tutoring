#include <iostream>
#include <cstdlib>
using namespace std;

int selectionSort(int arr[], int size) {
    int swaps = 0;

    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }

    return swaps;
}

int insertionSort(int arr[], int size) {
    int swaps = 0;

    for(int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }

        arr[j + 1] = key;
    }

    return swaps;
}

int bubbleSort(int arr[], int size) {
    int swaps = 0;

    for(int i = 0; i < size - 1; i++) {
        bool swapped = false;

        for(int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = true;
            }
        }

        if(!swapped) {
            break;
        }
    }

    return swaps;
}

void printArray(const int arr[], int size) {
    cout << "[ ";

    for(int i = 0; i < size; i++) {
        cout << arr[i];

        if(i < size - 1) {
            cout << ", ";
        }
    }

    cout << " ]";
}

int main(int argc, char* argv[]) {
    if(argc <= 1) {
        cout << "Usage: " << argv[0] << " <n1> <n2> ..." << endl;
        return 1;
    }

    int size = argc - 1;
    int* original = new int[size];
    int* selectionArray = new int[size];
    int* insertionArray = new int[size];
    int* bubbleArray = new int[size];

    for(int i = 0; i < size; i++) {
        original[i] = atoi(argv[i + 1]);
        selectionArray[i] = original[i];
        insertionArray[i] = original[i];
        bubbleArray[i] = original[i];
    }

    cout << "Received " << size << " input elements." << endl;
    cout << "Original Array: ";
    printArray(original, size);
    cout << endl;

    int selectionSwaps = selectionSort(selectionArray, size);
    int insertionSwaps = insertionSort(insertionArray, size);
    int bubbleSwaps = bubbleSort(bubbleArray, size);

    cout << "\n=== BENCHMARK RESULTS ===" << endl;
    cout << "Sorted Array:   ";
    printArray(selectionArray, size);
    cout << endl;

    cout << "\n- Selection Sort: " << selectionSwaps << " swaps" << endl;
    cout << "- Insertion Sort: " << insertionSwaps << " swaps" << endl;
    cout << "- Bubble Sort:    " << bubbleSwaps << " swaps" << endl;

    delete[] original;
    delete[] selectionArray;
    delete[] insertionArray;
    delete[] bubbleArray;

    return 0;
}
