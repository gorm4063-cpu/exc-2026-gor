#include <string.h>
#include <iostream>
using namespace std;
void sum(string a,string b) {
	int size_a=a.length();
	int size_b=b.length();
	int size;
	int diference;
	if(size_a>size_b) {
		size=size_a;
		diference=size_a-size_b;
	} else {
		size=size_b;
		diference=size_b-size_a;
	}
	int num_a[size]= {0};
	int num_b[size]= {0};
	if(size_a>size_b) {
		for(int i=0; i<size; i++) {
			num_a[i]=a[i]-'0';
		}
		for(int i=0; i<size_b; i++) {
			num_b[i+diference]=b[i]-'0';
		}
	} else {
		for(int i=0; i<size; i++) {
			num_b[i]=b[i]-'0';
		}
		for(int i=0; i<size_a; i++) {
			num_a[i+diference]=a[i]-'0';
		}
	}
	int sum[size];
	for(int i=0; i<size; i++) {
		sum[i]=num_a[i]+num_b[i];
	}
	for(int i=1; i<size; i++) {
		if(sum[i]>=10) {
			sum[i]%=10;
			sum[i-1]++;
			i=0;
		}
	}
	for(int i=0; i<size; i++) {
		cout<<sum[i];
	}
}





int main() {

	sum("999","100");



	return 0;
}