#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    
    // take the text input
    cout << "Enter text: ";
    getline(cin, text);
    
    // convert the text into lowercase for flexibility
    for (int i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }
    

    size_t pos = text.find("ada");
    int counter = 0;
    
    // loop and check if ada is present
    while (pos != string::npos) {
        counter++;                          // add one to counter
        pos = text.find("ada", pos + 1);    // move the start pos by 1
    }
    
    // display the number of ada detected
    cout << "Ada: " << counter << endl;
    
    return 0;
}