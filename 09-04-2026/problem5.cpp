#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    int n = 4;
    int matrix[n][n] = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
        
    };
    int k=n;
    while(k>=3){
        for (int i = 0; i < n; i++) {
            swap(matrix[n-k][i], matrix[k - 1][i]);
        }
        k--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}