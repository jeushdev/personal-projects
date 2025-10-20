#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double gwa;
    int offenses;

    // Set formatting for output
    cout << fixed << setprecision(2);

    cout << "Enter student's GWA: ";
    if (!(cin >> gwa)) {
        cerr << "Invalid input for GWA." << endl;
        return 1;
    }

    cout << "Enter number of major offenses: ";
    if (!(cin >> offenses)) {
        cerr << "Invalid input for offenses." << endl;
        return 1;
    }
    // Condition for Academic Award: (GPA <=2.0 ) AND (Offenses == 0)
    bool hasGoodGwa = (gwa <= 2.0);
    bool hasZeroOffenses = (offenses == 0);

    bool isEligibleForAward = hasGoodGwa && hasZeroOffenses;
    // Evaluate reasons for ineligibility


    // Output the GWA as part of the result
    cout << gwa << " - ";

    if (isEligibleForAward) {
        cout << "Academic Award Candidate" << endl;
    } else {
        if (!hasGoodGwa && hasZeroOffenses) {
            // Case 1: Low GWA, good discipline
            cout << "Needs Improvement in Grades" << endl;
        } else if (hasGoodGwa && !hasZeroOffenses) {
            // Case 2: Good GWA, poor discipline
            cout << "Needs Improvement in Discipline" << endl;
        } else {
            // Case 3: Both Low GWA and poor discipline
            cout << "Not Eligible for Awards" << endl;
        }
    }

    return 0;
}