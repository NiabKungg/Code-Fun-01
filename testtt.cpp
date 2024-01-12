#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

char calculateGrade(int score) {
    if (score >= 90) return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 60) return 'D';
    else return 'F';
}

double calculateGradeNumber(char ch){
    if (ch == 'A') return 4.00;
    else if (ch == 'B') return 3.00;
    else if (ch == 'C') return 2.00;
    else if (ch == 'D') return 1.00;
    else return 0;
}

int main() {
    string studentName;
    cin >> studentName;

    int numSubjects;
    cin >> numSubjects;

    vector<char> grades;
    int totalCredits = 0;
    double totalGPA = 0.0;

    for (int i = 0; i < numSubjects; ++i) {
        string subjectName;
        cin >> subjectName;

        int credits, score;
        cin >> credits >> score;

        char grade = calculateGrade(score);

        grades.push_back(grade);
        totalCredits += credits;
        totalGPA += calculateGradeNumber(grade) * credits; 
    }

    for (char grade : grades) {
        cout << grade << endl;
    }

    double GPA = totalGPA / totalCredits;
    cout << fixed << setprecision(1) << GPA << endl; 

    return 0;
}
