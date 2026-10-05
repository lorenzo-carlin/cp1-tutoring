#include <iostream>
#include <cmath>
using namespace std;

void calculateDistance(double x1, double y1, double x2, double y2, double *distance);

int main() {
    double x1, y1;
    double x2, y2;
    double distance;

    cout << "Enter Point 1 (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter Point 2 (x2 y2): ";
    cin >> x2 >> y2;

    calculateDistance(x1, y1, x2, y2, &distance);

    streamsize default_precision = cout.precision();

    cout << fixed;
    cout.precision(2);

    cout << "\nEuclidean distance between P1 and P2: " << distance << endl;

    cout.precision(default_precision);
    cout << defaultfloat;

    return 0;
}

void calculateDistance(double x1, double y1, double x2, double y2, double *distance) {
    double dx = x2 - x1;
    double dy = y2 - y1;

    *distance = sqrt(pow(dx, 2) + pow(dy, 2));
}