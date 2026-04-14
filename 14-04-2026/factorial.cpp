#include <iostream>
using namespace std;

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*fact(n-1);
}
int checknum(int k,int currentIndex=1){
    int currentFact=fact(currentIndex);
    if(fact(currentIndex)==k){
        return currentIndex;
    }
    if(currentFact>k){
        return -1;
    }
    return checknum(k,currentIndex + 1);
}
int main() {
    cout<<checknum(120);

    return 0;
}