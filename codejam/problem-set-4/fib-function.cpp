#include <iostream>
using namespace std;

int fib(int n);

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int element =fib(n);

    cout << "The element at position " << n << " is equal to " << element << endl;

    return 0;
}

int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}