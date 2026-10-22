#include <iostream>
using namespace std;

const int MATRIX_SIZE = 5;

void rotate90Clockwise(const int src[][5], int dest[][5], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            dest[j][size - 1 - i] = src[i][j];
        }
    }
}

void rotate90CounterClockwise(const int src[][5], int dest[][5], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            dest[size - 1 - j][i] = src[i][j];
        }
    }
}

bool areMatricesEqual(const int m1[][5], const int m2[][5], int size) {
    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            if(m1[r][c] != m2[r][c]) {
                return false;
            }
        }
    }
    return true;
}

void printMatrix(const int matrix[][5], int size) {
    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            cout << matrix[r][c] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int original[MATRIX_SIZE][MATRIX_SIZE];
    int rotatedCW[MATRIX_SIZE][MATRIX_SIZE];
    int restored[MATRIX_SIZE][MATRIX_SIZE];

    cout << "Enter 25 integer values for 5x5 matrix:" << endl;

    for(int r = 0; r < MATRIX_SIZE; r++) {
        for(int c = 0; c < MATRIX_SIZE; c++) {
            cin >> original[r][c];
        }
    }

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(original, MATRIX_SIZE);

    rotate90Clockwise(original, rotatedCW, MATRIX_SIZE);
    cout << "\nClockwise Rotated Matrix:" << endl;
    printMatrix(rotatedCW, MATRIX_SIZE);

    rotate90CounterClockwise(rotatedCW, restored, MATRIX_SIZE);
    cout << "\nRestored Matrix (Counter-Clockwise Applied):" << endl;
    printMatrix(restored, MATRIX_SIZE);

    if(areMatricesEqual(original, restored, MATRIX_SIZE)) {
        cout << "\nVerification Result: SUCCESS (Restored matrix matches original matrix!)" << endl;
    } else {
        cout << "\nVerification Result: FAILURE (Restored matrix does not match original matrix!)" << endl;
    }

    return 0;
}