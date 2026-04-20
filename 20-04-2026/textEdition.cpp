#include <string>
#include <vector>
#include <iostream>
using namespace std;

string deleteChar(vector<string>& text,int k){
    if(k>text.size() || text.empty()) return "";
    string res="";
    for(int i=0;i<text.size()-k;i++){
        res+=text[i];
    }
    return res;
}
string deleted_part(vector<string>& text,int k){
    if(k>text.size() || text.empty()) return "";
    string left="";
    for(int i=(text.size()-k);i<text.size();i++){
        left += text[i];
    }
    return left;   
}
string undo(vector<string>& text,string deleted_part,int k){
    string res=deleteChar(text,k) + deleted_part;
    return res;
}


int main(){
    string word;
    cout<<"enter word-";
    getline(cin,word);
    if (word.length() > 30) {
        cout << "Error: too many symbols" << endl;
        return 0;
    }    
    vector<string> text;
    for(char c: word){
        text.push_back(string(1, c));
    }
    for (int i = 1; i <text.size() - 1; i++) {
        if (text[i] == " " && text[i + 1] == " " && text[i - 1] != " ") {
            text.erase(text.begin() + i);
        }
    }
    cout << endl ;
    int deleteCharCounts;
    cout << "enter number of characters to delete: ";
    cin >> deleteCharCounts;
    cout<<"after deleting "<<deleteCharCounts<<" char - "<<deleteChar(text,deleteCharCounts)<<endl;
    string left=deleted_part(text,deleteCharCounts);
    cout<<"after undo - "<<undo(text,left,deleteCharCounts);
    return 0;
}