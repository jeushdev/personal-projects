#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Component {
    string name;
    double weight;
};

struct Course {
    string name;
    vector<Component> components;
};

float getEquivalent(double finalGrade);

int main() {

    vector<Course> courses = {
        {
            "CC 100",
            {
                {"Quiz 1", 0.05},
                {"Quiz 2", 0.05},
                {"Lab Activity", 0.10},
                {"Written Midterm", 0.20},
                {"Laboratory Midterm", 0.20},
                {"Project Proposal", 0.10},
                {"Final Project", 0.30}
            }
        },
        {
            "CC 101",
            {
                {"LabAct1", 0.10},
                {"LabAct2", 0.10},
                {"LabAct3", 0.10},
                {"Midterm Exam", 0.15},
                {"Midterm Lab", 0.10},
                {"Final Exam", 0.35},
                {"Written Quiz 1", 0.05},
                {"Written Quiz 2", 0.05}
            }
        }
    };

    char again;

    do {
        cout << "\n==== FINAL GRADE CALCULATOR ====\n";
        cout << "Choose a course:\n";

        // List all courses
        for (int i = 0; i < courses.size(); i++) {
            cout << i + 1 << ". " << courses[i].name << endl;
        }

        // Ask for input
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        // Validate input
        if (choice < 1 || choice > courses.size()) {
            cout << "Invalid choice. Try again\n";
            continue;
        }

        Course selected = courses[choice - 1];
        double finalGrade = 0;

        cout << "\n Enter scores for " << selected.name << ": \n";

        // List and ask the score on each component

        for (int i = 0; i < selected.components.size(); i++) {
            double score;
            cout << selected.components[i].name << " (1 - 100) : ";
            cin >> score;

            finalGrade += score *selected.components[i].weight;
        }

        // Display final grade
        cout << fixed << setprecision(2);
        cout << "\nFinal Grade for " << selected.name << ": " << finalGrade << endl;
        cout << "The equivalent grade is " << getEquivalent(finalGrade) << endl;


        cout << "\nDo you want to calculate another course? (Y/N): ";
        cin >> again;
        
    }while (again == 'Y' || again == 'y');

    return 0;
}

float getEquivalent(double finalGrade) {
    if (finalGrade >= 97.1) return 1.0;
    else if (finalGrade < 97.1 && finalGrade >= 94.96 ) return 1.25;
    else if (finalGrade < 94.96 && finalGrade >= 91.93 ) return 1.50;
    else if (finalGrade < 91.93 && finalGrade >= 88.90 ) return 1.75;
    else if (finalGrade < 88.90 && finalGrade > 85.87 ) return 2.0;
    else if (finalGrade < 97.1 && finalGrade > 94.96 ) return 2.25;
    else return 5.0;
}