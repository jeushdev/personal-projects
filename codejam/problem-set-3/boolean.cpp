#include <iostream>
using namespace std;

int main () {
    bool testExpr1 = 1, testExpr2 = 0;
    // note: 0 is false, 1 is true

    string text = " ", value = "5";
    bool item1 = testExpr1 && testExpr2;
    bool item2 = testExpr1 || testExpr2;
    bool item3 = !testExpr1;
    bool item4 = !(!(!(!(!(!(!(!(item1 || item2))))))));
    bool item5 = !(!(!(!(!(!(!(!(!(item1 || item2)))))))));
    bool item6 = (item1) || !(item1);
    bool item7 = !(!(!(!(!((item1) || (item2))))));
    bool item8 = ((36 % 5 == 36 / 5) && (0 == '0'));
    bool item9 = (text == "NULL");
    bool item10 = (value != "5");
    
    cout << boolalpha;
    cout << "1. " << item1 << endl;
    cout << "2. " << item2 << endl;
    cout << "3. " << item3 << endl;
    cout << "4. " << item4 << endl;
    cout << "5. " << item5 << endl;
    cout << "6. " << item6<< endl;
    cout << "7. " << item7 << endl;
    cout << "8. " << item8 << endl;
    cout << "9. " << item9 << endl;
    cout << "10. " << item10 << endl;
    return 0;
}