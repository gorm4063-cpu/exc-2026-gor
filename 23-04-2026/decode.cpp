#include <utility>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	string code;
	cout << "Please enter code you want to decode - ";
	cin >> code ;
	int size = code.length();
	if(size > 30 ) {
		cout << "too many simvols " ;
		return 0;
	}  //check cases;
	for(char c:code) {
		if(c == 32) {
			cout << " invalit input" ;
			return 0;
		}
	} //check cases;
	for(char c:code) {
		if( c > 65 && c < 90) {
			cout << "invlaid input";
			return 0;
		}
	} //check cases;
	int nums[size];
	for(int i = 0 ; i < size ; i++) {
		nums[i] = code[i] - '0' ;       //divaded my string into separate elements and chenge its into integer
	}
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //make pair to do decoding;
	pair<int,char> arr[26];
	for(int i = 1; i <= 26 ; i++) {
		arr[i-1]= {i,alphabet[i-1]};
	}
	cout << "Single digit decode: ";
	for(int i = 0 ; i < size; i++) {
		if(nums[i] == 0 && i == 0) {
			cout << "invalid input: can't be decoted";
			return 0;
		} else if(i + 1 < size && nums[i + 1] == 0) {
			int val = nums[i]*10;
			if(val <= 26 && val > 0 ) {
				cout << arr[val - 1].second;
				i++;
			} else {
				cout << "invalid input ";
				return 0;
			}
		} else {
			cout << arr[nums[i] - 1].second;
		}
	}
	cout << endl ;
	cout << "Double digit decode: ";
	for(int i = 0; i < size - 1 ; i += 2) {
		if(nums[i]*10 + nums[i+1] <= 26 && nums[i]*10 + nums[i+1] >= 10) {
			int val = nums[i]*10 + nums[i+1];
			cout << arr[val - 1 ].second;
		}
	}

	return 0;
}