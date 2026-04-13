#include <cmath>
#include <string.h>
#include <iostream>
using namespace std;
void sum(string a,string b) {
	int count=0;
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
	if(size_a==size_b && num_a[0]>num_b[0]) {
		for(int i=size-1; i>0; i--) {
			if(num_a[i]>=num_b[i]) {
				sum[i]=num_a[i]-num_b[i];
			} else {
				if(num_a[i-1]!=0) {
					num_a[i-1]--;
					num_a[i]+=10;
					sum[i]=num_a[i]-num_b[i];
				} else {
					while(num_a[i-1]==0) {
						i--;
						count++;
					}
					num_a[i-1]--;
					num_a[i+count]+=10;
					sum[i+count]=num_a[i+count]-num_b[i+count];
					i+=count;
				}
			}
			sum[0]=num_a[0]-num_b[0];
		}

		for(int i=0; i<size; i++) {
			cout<<sum[i];
		}
	} else {
		for(int i=size-1; i>0; i--) {
			if(num_b[i]>=num_a[i]) {
				sum[i]=num_b[i]-num_a[i];
			} else {
				if(num_b[i-1]!=0) {
					num_b[i-1]--;
					num_b[i]+=10;
					sum[i]=num_b[i]-num_a[i];
				} else {
					while(num_b[i-1]==0) {
						i--;
						count++;
					}
					num_b[i-1]--;
					num_b[i+count]+=10;
					sum[i+count]=num_b[i+count]-num_a[i+count];
					i+=count;
				}
			}
			sum[0]=num_b[0]-num_a[0];
		}
		cout<<"-";
		for(int i=0; i<size; i++) {
			if(sum[i]==0) {
				continue;
			}
			cout<<sum[i];
		}
	}
}





int main() {

	sum("15","180");



	return 0;
}