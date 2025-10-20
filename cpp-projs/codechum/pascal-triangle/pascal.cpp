#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    vector<vector<int>> triangles(rows);
    
    for (int i = 0; i < rows; i++) {
        triangles[i].resize(i + 1); 
        
        triangles[i][0] = 1;          
        triangles[i][i] = 1;      
        
        for (int j = 0; j < i; j++) {
            triangles[i][j] = triangles[i - 1][j - 1] + triangles[i - 1][j];
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            cout << triangles[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}