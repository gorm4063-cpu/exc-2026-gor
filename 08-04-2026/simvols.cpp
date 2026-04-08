#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string arr[] = {"(", "[", "{", "}", "]", ")"};
    int size = sizeof(arr) / sizeof(arr[0]);
    stack<string> s;
    if (size % 2 != 0) {
        cout << "false" << endl;
        return 0;
    }
    for (int i = 0; i < size; i++) {
        string current = arr[i];
        if (current == "(" || current == "[" || current == "{") {
            s.push(current);
        } 
        else {
            if (s.empty()) {
                cout << "false" << endl;
                return 0;
            }
            string top = s.top();
            if ((current == ")" && top == "(") || (current == "]" && top == "[") || (current == "}" && top == "{")) {
                s.pop(); 
            } else {
                cout << "false" << endl;
                return 0;
            }
        }
    }
    if (s.empty()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}