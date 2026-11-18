#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    string firstName;
    string lastName;
    int grades[3];
    double average;
};

double computeAverage(const Student& student) {
    double sum = 0;

    for(int i = 0; i < 3; i++) {
        sum += student.grades[i];
    }

    return sum / 3.0;
}

int loadStudents(const string& fileName, Student students[], int maxStudents) {
    ifstream input(fileName);

    if(!input.is_open()) {
        return -1;
    }

    int count;
    input >> count;

    if(!input || count <= 0 || count > maxStudents) {
        return -1;
    }

    for(int i = 0; i < count; i++) {
        input >> students[i].firstName >> students[i].lastName
              >> students[i].grades[0] >> students[i].grades[1] >> students[i].grades[2];

        if(!input) {
            return -1;
        }

        students[i].average = computeAverage(students[i]);
    }

    input.close();

    return count;
}

void writeReport(const Student students[], int count, ostream& out) {
    ios::fmtflags oldFlags = out.flags();
    streamsize oldPrecision = out.precision();

    out << fixed << setprecision(2);

    out << "=== STUDENT REPORT ===" << endl;

    double classSum = 0;
    int bestIndex = 0;
    int passed = 0;

    for(int i = 0; i < count; i++) {
        out << students[i].firstName << " " << students[i].lastName << ": "
            << (double)students[i].grades[0] << " "
            << (double)students[i].grades[1] << " "
            << (double)students[i].grades[2]
            << " -> Average: " << students[i].average << endl;

        classSum += students[i].average;

        if(students[i].average > students[bestIndex].average) {
            bestIndex = i;
        }

        if(students[i].average >= 6.0) {
            passed++;
        }
    }

    out << endl;
    out << "Class average: " << classSum / count << endl;
    out << "Best student: " << students[bestIndex].firstName << " "
        << students[bestIndex].lastName << " (" << students[bestIndex].average << ")" << endl;
    out << "Passed: " << passed << " | Failed: " << count - passed << endl;

    out.flags(oldFlags);
    out.precision(oldPrecision);
}

bool saveReport(const string& fileName, const Student students[], int count) {
    ofstream output(fileName);

    if(!output.is_open()) {
        return false;
    }

    writeReport(students, count, output);
    output.close();

    return true;
}

int main() {
    string fileName;

    cout << "Enter students file name: ";
    cin >> fileName;

    Student students[MAX_STUDENTS];
    int count = loadStudents(fileName, students, MAX_STUDENTS);

    if(count < 0) {
        cout << "Error: could not load a valid student list from \"" << fileName << "\"." << endl;
        return 1;
    }

    cout << endl;
    writeReport(students, count, cout);

    if(saveReport("report.txt", students, count)) {
        cout << "\nReport written to report.txt." << endl;
    } else {
        cout << "\nError: could not write report.txt." << endl;
        return 1;
    }

    return 0;
}
