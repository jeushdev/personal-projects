#include <iostream>
using namespace std;

bool isPalindrome(int x);
int reverseNumber(int x);

int main() {
    int x;
    cout << "Input: ";
    cin >> x;
    
    cout << boolalpha <<  "Output: " << isPalindrome(x) << endl;

    return 0;
}

bool isPalindrome(int x) {
    if (x < 0) return false;
    int rev = reverseNumber(x);
    return (rev == x);
}

int reverseNumber(int x) {
    int revx = 0, pal = 0;
    while(x != 0) {
        revx = x % 10;
        x /= 10;
        pal = pal * 10 + revx;
    }
    return pal;
}
