
//my code algorithm works for odd size matrix and only for 4 and 6 even size matrix; 

#include <iostream>
using namespace std;
int main() {
	int n;
	int count = 0;
	cout << " enter the size of matrix -" ;
	cin >> n;
	if(n <= 3 ){
	    cout<<"invalid input! size must be bigger than 3";
	    return 0;
	} 
	char matrix[n][n];
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n; j ++) {
			matrix[i][j] = '.';
		}
	}

	if(n % 2 != 0) {
		for(int j = 0 ; j < n; j ++) {
		    int i=2 * j;
			if(i > n) {
				i = i - n  ;
			}
			matrix[i][j] = 'Q';

		}
	}
	if(n % 2 == 0) {
		for(int j = 0 ; j < n; j ++) {
		    int i=2 * j + 1;
			if(i > n) {
				i = i - n - 1 ;
			}
			matrix[i][j] = 'Q';

		}
	}
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n; j ++) {
			cout << matrix[i][j] << " " ;
		}
		cout << endl ;
	}
	return 0;
}