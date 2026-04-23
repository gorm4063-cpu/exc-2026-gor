#include <iostream>
#include <thread>
using namespace std;
void move(char arr[12][12], char direction, int i, int j) {
	if(i == 11 || j == 11 || (j == 0 && i != 2)) {
		cout << "we find the exit!" ;
		return;
	}
	if( i == 0 ) {
		cout << "the exit dont exist" ;
		return;
	}


	arr[i][j] = '-' ;
    
	cout << endl;
	int next_i = i, next_j = j;

	if (arr[i][j + 1] == ' ') {
		next_j = j + 1;
		direction = '>';
	} else if (arr[i + 1][j] == ' ') {
		next_i = i + 1;
		direction = '~';
	} else if (arr[i][j - 1] == ' ') {
		next_j = j - 1;
		direction = '<';
	} else if (arr[i - 1][j] == ' ') {
		next_i = i - 1;
		direction = '^';
	}else{
	    cout << "stuck" ;
	    return;
	}
	
	arr[next_i][next_j] = 'o';
	cout << "\033[2J\033[1;1H";
	for(int a = 0 ; a < 12 ; a++) {
		for(int b = 0 ; b < 12 ; b++) {
			cout << arr[a][b];
		}
		cout << endl ;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	move(arr, direction, next_i, next_j);
}

int main()
{
	int i;
	int j;
	char direction = '>';
	i = 2;
	j = 0;

	cout << "\nPress ENTER to see the object's next steps\n";

	char arr[12][12] = {

		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#',
		'o', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#',
		'#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#',
		'#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', '#',
		'#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ',
		'#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
		'#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
		'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#',
		'#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#',
		'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
	};

	for(int i = 0 ; i < 12 ; i++) {
		for(int j = 0 ; j < 12 ; j++) {
			cout << arr[i][j];
		}
		cout << endl ;
	}
	move(arr, direction, i, j);

	return 0;
}