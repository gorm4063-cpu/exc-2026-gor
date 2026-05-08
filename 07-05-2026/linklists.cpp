
#include <vector>
#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	static node* addnode(int newdata , node* previusnode){
        node* newnode = new node();
        newnode->data = newdata ;
        newnode->next = nullptr;
        if(previusnode->next = nullptr){
            previusnode->next = newnode;
        }
        return newnode ;
	}
};



int main() {
    node* ob1 = new node();
    ob1->data = 1;
    
    node* ob2 = node::addnode(10,ob1);
    node* ob3 = node::addnode(15,ob2);
    
    cout << ob2->data << "\t" << ob2->next;
    
	return 0;
}