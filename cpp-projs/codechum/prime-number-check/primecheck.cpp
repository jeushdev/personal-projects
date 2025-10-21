#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    bool isPrime = true;

    if (num <= 1) {
        isPrime = false; // 0, 1, and negatives are not prime
    } 
    else if (num <= 3) {
        isPrime = true;  // 2 and 3 are prime
    }
    else if (num % 2 == 0) {
        isPrime = false; // even numbers > 2 are not prime
    }
    else {
        int n = 3;
        do {
            if (num % n == 0) {
                isPrime = false;
                break;
            }
            n += 2; // skip even numbers
        } while (n <= sqrt(num));
    }

    if (isPrime)
        cout << num << " is a prime number\n";
    else
        cout << num << " is not a prime number\n";

    return 0;
}
