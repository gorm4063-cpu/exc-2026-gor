#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findnum(vector<int> &arr,int num,int begin,int end) {
    if(begin > end ){
        cout << "number not found ";
        return -1;
    }
    int middleindex =  (end + begin)/2;
    int middleval = arr[middleindex];
    if(num == middleval){
        return middleindex;
    }
    if(num < middleval){
        return findnum(arr,num,begin,middleindex - 1);
    }else{
        return findnum(arr,num,middleindex + 1,end);
    }

}

int main() {
	int num;
	cout << "enter number - " ;
	cin >>num;
	vector<int> arr = {5, 2, 8, 1, 9, 10, 15, 20, 500, -5, -8, 92};
	arr.push_back(num);
	sort(arr.begin(),arr.end());
	int size = arr.size();
    int res = findnum(arr , num , 0 , arr.size() - 1);
    cout <<"founding number index is - "<< res <<" || number is - " <<arr[res];

	return 0;
}