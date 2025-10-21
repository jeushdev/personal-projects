#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string input;
    cout << "Enter a binary number: ";
    cin >> input;

    int size = input.length();
    int decimal = 0;
    int counter = size - 1;
    int power = 1;

    do {
        int bit = input[counter] - '0'; 
        decimal += bit * power;         
        power *= 2;                     
        counter--;                      
    } while (counter >= 0);

    cout << "Decimal equivalent: " << decimal;
}
