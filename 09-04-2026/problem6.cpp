#include <iostream>
#include <algorithm> 
#include <cmath>
using namespace std;
int derivate(int x){
    float d;
    d=2*x*pow(x,-1)*cos(log(pow(x,2)));
    return d;
}


int main() {
    int x=1;
    string fuctions[]={"sin","log","square"};
    cout<<derivate(x);
    return 0;
}