#include <iostream>
using namespace std;

const int GRID_SIZE = 10;

bool isFullyColonized(const int grid[][GRID_SIZE], int rows) {
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < GRID_SIZE; c++) {
            if(grid[r][c] == 0) {
                return false;
            }
        }
    }
    return true;
}

void simulateOneDay(int grid[][GRID_SIZE], int rows) {
    int temp[GRID_SIZE][GRID_SIZE];

    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < GRID_SIZE; c++) {
            temp[r][c] = grid[r][c];
        }
    }

    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < GRID_SIZE; c++) {
            if(temp[r][c] == 1) {
                if(r > 0) grid[r - 1][c] = 1;
                if(r < rows - 1) grid[r + 1][c] = 1;
                if(c > 0) grid[r][c - 1] = 1;
                if(c < GRID_SIZE - 1) grid[r][c + 1] = 1;
            }
        }
    }
}

void printGrid(const int grid[][GRID_SIZE], int rows) {
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < GRID_SIZE; c++) {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];

    cout << "Enter initial " << GRID_SIZE << "x" << GRID_SIZE << " matrix (0 or 1):" << endl;
    for(int r = 0; r < GRID_SIZE; r++) {
        for(int c = 0; c < GRID_SIZE; c++) {
            cin >> grid[r][c];
        }
    }

    int days = 0;
    cout << "\nSimulating colonization process..." << endl;

    while(!isFullyColonized(grid, GRID_SIZE)) {
        simulateOneDay(grid, GRID_SIZE);
        days++;
        cout << "Day " << days << ":" << endl;
        printGrid(grid, GRID_SIZE);
        cout << endl;
    }

    cout << "\nTotal days required for full colonization: " << days << endl;

    return 0;
}