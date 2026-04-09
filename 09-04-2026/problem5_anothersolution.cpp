#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    int n = 4;
    int matrix[n][n] = {
        {1, 2, 3,   10},
        {4, 5, 6,   11},
        {7, 8, 9,   12},
        {14, 15, 16, 17}
    };
    for (int i = 0; i < n; i++) {
        for (int j =0; j < n; j++) {
            cout<<matrix[n-j-1][i]<<" ";
        }
        cout<<endl;
    }
  
    return 0;
}