#include <iostream>
using namespace std;

int fib(int n);

int main() {
    int n;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonnaci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fib(i);
        if (i != n - 1) {
            cout << ", ";
        }

    } 
}

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}
