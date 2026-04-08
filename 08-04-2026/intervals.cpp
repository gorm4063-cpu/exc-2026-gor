#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int intervals[]={1,3,6,9};
    int newinterval[2]={2,5};
    int size=sizeof(intervals)/sizeof(intervals[0]);
    int  newsize=size+2;
    int newarr[newsize];
    for(int i=0;i<size;i++){
        newarr[i]=intervals[i];
    }
    int a=newinterval[0];
    int b=newinterval[1];
    newarr[newsize-1]=a;
    newarr[newsize-2]=b;    
    sort(newarr,newarr + newsize);
    int index_a=0;
    int index_b=0;
    for(int i=0;i<newsize;i++){
        if(newarr[i]==a){
            index_a=i;
        }
        if(newarr[i]==b){
            index_b=i;
        }
    }
    for(int i=0;i<size;i++){
        if(intervals[i]==b){
            index_b++;
        }
        if(intervals[i]==a){
            index_a--;
        }

    }
    cout<<"[";
    for(int i=0;i<newsize;i++){
        if(i>=index_a && i<index_b){
            continue;
        }
        cout<<newarr[i]<<" ";
    }
    cout<<"]";
    return 0;
}