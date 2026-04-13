#include <iostream>
#include <string>
using namespace std;

int main() {
	int count=1;
	string res="";
	string word="aabbbbcd";
	int size=word.length();
	for(int i=0; i<size; i++) {
		while (i+1<size && word[i]==word[i+1]) {
			count++;
			i++;
		}
		if(count>1){
             res+=to_string(count);
		}
		res += word[i];
		count = 1;
	}
	cout<<res;
	return 0;
}