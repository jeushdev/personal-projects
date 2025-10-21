#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    
    vector<vector<int>> spiral(n, vector<int>(n));
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    
    int num = 1;
    while (num <= n*n){
        for (int i = left; i <= right && num <= n * n; i++) {
            spiral[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom && num <= n * n; i++) {
            spiral[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left && num <= n * n; i--) {
            spiral[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top && num <= n * n; i--) {
            spiral[i][left] = num++;
        }
        left++;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cout << spiral[i][j] << " ";
        }
        cout << endl;
    }
}