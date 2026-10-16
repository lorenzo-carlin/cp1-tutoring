#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void simulateTargetRolls(int target, int &totalRolls, int &finalScore);

int main() {
    srand(time(nullptr));

    int target;
    cout << "Enter target score (>= 10): ";
    cin >> target;

    if(target < 10) {
        cout << "Error: Target score must be at least 10." << endl;
        return 1;
    }

    int totalRolls = 0;
    int finalScore = 0;

    cout << "Simulating dice rolls..." << endl;

    simulateTargetRolls(target, totalRolls, finalScore);

    cout << "Target " << target << " reached!" << endl;
    cout << "- Total three-dice rolls required: " << totalRolls << endl;
    cout << "- Final cumulative score: " << finalScore << endl;

    return 0;
}

void simulateTargetRolls(int target, int &totalRolls, int &finalScore) {
    totalRolls = 0;
    finalScore = 0;

    while (finalScore < target) {
        int die1 = (rand() % 6) + 1;
        int die2 = (rand() % 6) + 1;
        int die3 = (rand() % 6) + 1;

        int currentRoll = die1 + die2 + die3;
        finalScore += currentRoll;
        totalRolls++;
    }
}