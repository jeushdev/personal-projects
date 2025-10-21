#include <iostream>
#include <string>
using namespace std;

bool isSubseq (string first, string second);

int main() {
    string first, second;
    cout << "Enter string 1: ";
    getline(cin, first);
    cout << "Enter string 2: ";
    getline(cin, second);
    
    
    if (isSubseq(first, second)) {
        cout << second << " is a subsequence of " << first << endl;
    }
    else {
        cout << second << " is not a subsequence of " << first << endl;
    }
    
    return 0;
}

bool isSubseq(string first, string second) {
    int firstLength = first.length();
    int secondLength = second.length();
    int j = 0;  // index for first string

    // For each character in 'second'
    for (int i = 0; i < secondLength; i++) {
        bool found = false;  // flag to check if current char is found

        // search for second[i] in first, starting from current j
        for (; j < firstLength; j++) {
            if (second[i] == first[j]) {
                found = true;
                j++;  // move j forward for next search
                break;  // go to next character in 'second'
            }
        }

        // if not found, it's not a subsequence
        if (!found)
            return false;
    }

    // all characters found in order
    return true;
}
