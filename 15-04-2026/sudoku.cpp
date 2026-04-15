
#include <iostream>
#include <string>
using namespace std;
bool box( char arr[9][9],int line,int row ) {
	string seen="";
	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			char val = arr[line + i][row + j];
			if (val != '.') {
				if( seen.find(val)!=string::npos) {
					return false;
				} else {
					seen+=val;
				}
			}
		}
	}
	return true;
}
bool line( char arr[9][9],int line) {
	int size = 9;
	string seen="";
	for(int i = 0; i < size; i++) {
		char val = arr[line][i];
		if(val != '.') {
			if( seen.find(val) != string::npos ) {
				return false;
			}else{
			    seen += val;
			}
		}
	}
	return true;
}
bool column( char arr[9][9],int row ) {
	int size = 9;
	string seen=";";
	for( int i = 0; i < size; i++ ) {
	    char val = arr[i][row];
	    if(val != '.')
            if( seen.find(val) != string::npos ){
                return false;
            }else{
                seen += val;
            }
		}
	return true;
}
bool sudoku( char sud[9][9] ) {
	int size = 9;
	for(int i = 0; i < size; i++) {
		if( !line(sud,i) || !column(sud,i) ) {
			return false;
		}
		if(i%3==0) {
			for( int j = 0; j < size; j+=3 ) {
				if ( !box(sud, i, j) ) {
					return false;
				}
			}
		}
	}
	return true;
}


int main() {
	char sud[9][9] = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	cout << ( sudoku(sud) ? "sudoku is valid" : "sudoku isn't valid" ) ;
	return 0;
}