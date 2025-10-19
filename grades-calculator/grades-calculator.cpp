#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Course {
    string name;
    map<string, double> components;
};

int main() {
    cout << "\nGrades Calculator\n";

    // Ask a subject
    string course;
    cout << "What course do you want to compute? ";
    getline(cin, course);

    // Ask for the scores in the activities on that subject


    // Calculate the final grade
    // Ask if will continue to another subject or end

}