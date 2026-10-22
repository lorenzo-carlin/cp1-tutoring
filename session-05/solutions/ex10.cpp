#include <iostream>
using namespace std;

const int DAYS = 10;

double calculateAverageSteps(const int steps[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += steps[i];
    }
    return ((double) sum / ((double) size));
}

int findBestDayIndex(const int steps[], int size) {
    int bestIdx = 0;
    for(int i = 1; i < size; i++) {
        if(steps[i] > steps[bestIdx]) {
            bestIdx = i;
        }
    }
    return bestIdx;
}

int countLongestStreak(const int steps[], int size, int goal) {
    int currentStreak = 0;
    int maxStreak = 0;

    for(int i = 0; i < size; i++) {
        if(steps[i] >= goal) {
            currentStreak++;
            if(currentStreak > maxStreak) {
                maxStreak = currentStreak;
            }
        } else {
            currentStreak = 0;
        }
    }
    return maxStreak;
}

int main() {
    int steps[DAYS];
    int goal;

    cout << "Enter " << DAYS << " daily step counts:" << endl;
    for(int i = 0; i < DAYS; i++) {
        cin >> steps[i];
        if(steps[i] < 0) {
            cout << "Error: Step count cannot be negative." << endl;
            return 1;
        }
    }

    cout << "Enter daily step goal: ";
    cin >> goal;
    if(goal < 0) {
        cout << "Error: Step goal cannot be negative." << endl;
        return 1;
    }

    double avgSteps = calculateAverageSteps(steps, DAYS);
    int bestDay = findBestDayIndex(steps, DAYS);
    int maxStreak = countLongestStreak(steps, DAYS, goal);

    cout << "\n=== FITNESS REPORT ===" << endl;
    cout << "- Average daily steps: " << avgSteps << " steps" << endl;
    cout << "- Best Day: Day " << bestDay << " (" << steps[bestDay] << " steps)" << endl;
    cout << "- Longest Active Streak (>= " << goal << " steps): " << maxStreak << " consecutive days" << endl;

    return 0;
}