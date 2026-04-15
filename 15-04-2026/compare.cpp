#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string compare( string num , int base1 , int base2 ) {
	long long num1 = 0;
	int size = num.length();
	if( base1 != 10 ) {
		for( int i = 0; i < size; i++ ) {
			int digit = num[i]-'0';
			num1 += digit*pow( base1,size - 1 - i );
		}
	} else {
		num1 = stoll(num);
	}

	string res = "";
	while ( num1 > 0 ) {
		int left = num1 % base2;
		res += to_string(left);
		num1 /= base2;
	}

	reverse( res.begin(),res.end() );
	return res;
}

int main() {
	cout<<compare( "15", 9 , 2 );


	return 0;
}