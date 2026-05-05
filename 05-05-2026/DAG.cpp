#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DAG {
private:
	int id;
	int lengthFromNext;
	bool hasEnter;

public:
	DAG(int id, int lengthFromNext, bool hasEnter = true) {
		this->id = id;
		this->lengthFromNext = lengthFromNext;
		this->hasEnter = hasEnter;
	}

	int getID() const {
		return id;
	}

	bool getEnter() const {
		return hasEnter;
	}

	int getLength() const {
		return lengthFromNext;
	}


	void setLength(int newLength) {
		lengthFromNext = newLength;
	}

};


int main() {
	vector<DAG> arr = {
		{5, 10, false},
		{6, 30},
		{4, 20, false},
		{7, 12, false},
		{3, 5},
		{2, 4},
		{1, 3}
	};
	sort(arr.begin(),arr.end(),[](const DAG& a, const DAG& b) {
		return a.getID() > b.getID(); // sort my vector objects by their id (in decreasing way)
	});

	vector<DAG> str;

	for (auto it = arr.begin(); it != arr.end(); ) {
		if (!it->getEnter()) {
			str.push_back(*it);
			it = arr.erase(it);
		} else {
			++it;
		}
	}
	cout << "posible ways is " << endl ;
	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i).getID() << "->";
		int totalLength = str.at(i).getLength();
		for (int j = 0; j < arr.size(); j++) {
			if(arr.at(j).getID() < str.at(i).getID()) {
				cout << arr.at(j).getID() << "->";
				totalLength += arr.at(j).getLength();
			}else{
			    continue;
			}
		}
		str.at(i).setLength(totalLength);
		cout << "0" <<endl;
	}

	int index = 0;
	int maxlength = 0;

	if (!str.empty()) {
		maxlength = str.at(0).getLength();
		for (int i = 1; i < str.size(); i++) {
			if (str.at(i).getLength() > maxlength) {
				maxlength = str.at(i).getLength();
				index = i;
			}
		}
	}
	if (!str.empty()) {
		cout << "max length way is || " << str.at(index).getID() << "->";
		for (int i = 0; i < arr.size(); i++) {
			if(arr.at(i).getID() < str.at(index).getID()) {
				cout << arr.at(i).getID() << "->";
			}else{
			    continue;
			}
		}
		cout << "0 || " << maxlength << endl;
	} else {
		cout << "No elements found in str." << endl;
	}
	int minlength = 0 ;
	int index2 = 0;
	if (!str.empty()) {
		minlength = str.at(0).getLength();
		for (int i = 1; i < str.size(); i++) {
			if (str.at(i).getLength() < minlength) {
				minlength = str.at(i).getLength();
				index2 = i;
			}
		}
	}
	if (!str.empty()) {
		cout << "min length way is || " << str.at(index2).getID() << "->";
		for (int i = 0; i < arr.size(); i++) {
			if(arr.at(i).getID() < str.at(index2).getID()) {
				cout << arr.at(i).getID() << "->";
			}else{
			    continue;
			}
			}
		cout << "0 || " << minlength << endl;
	} else {
		cout << "No elements found in str." << endl;
	}

	return 0;
}