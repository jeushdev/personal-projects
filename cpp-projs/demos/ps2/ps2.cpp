#include <iostream>
#include <iomanip> // Needed for formatting
using namespace std;

// Function Prototype
// BLANK A: Define the function prototype for calculateInterest
double calculateInterest(double principal, double ratePercentage, double timeYears);

// Main Function
int main() {
    double principal = 10000.0;
    double rate = 4.5; // 4.5%
    double time = 2.0; // 2 years

    // BLANK C: Call the function and store the result
    double interest = calculateInterest(principal, rate, time);

    cout << "Principal: " << principal << endl;
    cout << "Rate: " << rate << "%" << endl;
    cout << "Time: " << time << " years" << endl;
    cout << "Simple Interest: ";
    // BLANK E: Apply formatting to output the interest
    cout << fixed << setprecision(2);
    cout << interest << endl; // BLANK F: Output the variable

    return 0;
}

// Function Definition
// BLANK G: Define the function body for calculateInterest
double calculateInterest(double principal, double ratePercentage, double timeYears) {
    // BLANK H: Convert rate from percentage to decimal
    double rateDecimal = ratePercentage / 100.0; // BLANK I: Conversion formula
    
    // BLANK J: Calculate interest
    double interest = principal * rateDecimal * timeYears;
    
    // BLANK K: Return the calculated interest
    return interest; // BLANK L: Variable to return
}
