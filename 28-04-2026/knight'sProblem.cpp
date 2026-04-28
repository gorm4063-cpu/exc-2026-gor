#include <iostream>
#include <vector>
using namespace std;
bool checkmatrix(char matrix[8][8])
{
	for(int k = 0 ; k < 8 ; k++) {
		for( int z = 0; z < 8 ; z++) {
			if(matrix[k][z] != 'h') return false;
		}
	}
	return true ;
}
void move_horse(char matrix[8][8], int i, int j )
{
	int previus_i = i;
	int previus_j = j;
	matrix[0][0] = 'h';
	vector<int> ways;
	if (i - 2 >= 0 && j - 1 >= 0 && matrix[i - 2][j - 1] == '#') // checking the posible way to move and saving it into vector
	{
		ways.push_back(i - 2);
		ways.push_back(j - 1);
	}
	if (i - 2 >= 0 && j + 1 < 8 && matrix[i - 2][j + 1] == '#')
	{
		ways.push_back(i - 2);
		ways.push_back(j + 1);
	}
	if (i + 2 < 8 && j + 1 < 8 && matrix[i + 2][j + 1] == '#')
	{
		ways.push_back(i + 2);
		ways.push_back(j + 1);
	}
	if (i + 2 < 8 && j - 1 >= 0 && matrix[i + 2][j - 1] == '#')
	{
		ways.push_back(i + 2);
		ways.push_back(j - 1);
	}
	if (j - 2 >= 0 && i + 1 && matrix[i + 1][j - 2] == '#')
	{
		ways.push_back(i + 1);
		ways.push_back(j - 2);
	}
	if(j - 2 >= 0 && i - 1 >=0 && matrix[i - 1][j - 2] == '#') {
		ways.push_back(i - 1);
		ways.push_back(j - 2);
	}
	if (j + 2 < 8 && i + 1 < 8 && matrix[i + 1][j + 2] == '#')
	{
		ways.push_back(i + 1);
		ways.push_back(j + 2);
	}
	if(j + 2 < 8 && i - 1 >= 0 && matrix[i - 1][j + 2] == '#') {
		ways.push_back(i - 1);
		ways.push_back(j + 2);
	}
	if (ways.empty()) {  // in case that thare are no free sapce to move we change previus move coordinats cell to #
		if (checkmatrix(matrix)) {
			cout << "Success! Board full." << endl;
		} else {
			matrix[previus_i][previus_j] = '#';
			return move_horse(matrix, previus_i, previus_j);
		}
		return;
	}

	int next_i = ways[0];
	int next_j = ways[1];

	matrix[next_i][next_j] = 'h';
	for(int k = 0 ; k < 8 ; k++) {
		for(int z = 0; z < 8 ; z++) {
			cout << matrix[k][z] << " " ;
		}
		cout << endl ;
	}

	cout << endl ;
	if (checkmatrix(matrix))
	{
		cout << "Possible!" << endl;
		return;
	}
	return move_horse(matrix, next_i, next_j);
}

int main()
{

	char matrix[8][8];
	for(int k = 0 ; k < 8 ; k++) {
		for(int z = 0; z < 8 ; z++) {
			matrix[k][z] = '#' ;
		}
	}
	move_horse(matrix, 0, 0);
	return 0;
}