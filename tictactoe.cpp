#include <iostream>

using namespace std;

char grid[3][3] = {{}, {}, {}};

void printGrid();
void takeUserInput(int);
bool checkWinner();

int main() {	
	printGrid();
	
	for (int i = 0; i < 9; i++) {
		takeUserInput(1);
		if (checkWinner()) {
			cout << "\n--------------------------\n";
			cout << " Player 1 has won the game!";
			cout << "\n--------------------------\n";
			break;
		}
		takeUserInput(2);
		if (checkWinner()) {
			cout << "\n--------------------------\n";
			cout << " Player 2 has won the game!";
			cout << "\n--------------------------\n";
			break;
		}
	}
}

void takeUserInput(int player) {
	int row, col;
	cout << endl;
	cout << (player == 2 ? "Player2 (O)" : "Player1 (X)") << endl;
	cout << "Row: ";
	cin >> row;
	cout << "Column: ";
	cin >> col;
	
	// TODO: Check if the position is already reserved or not
//	if (grid[row-1][col-1] != NULL) {
//		cout << "\nPosition is already filled, choose another one.\n";
//		continue;
//	}
	grid[row-1][col-1] = (player == 1 ? 'X' : 'O');
	printGrid();
}

void printGrid() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "  " << grid[i][j] << " |" << " ";
			if (j == 2) cout << endl;
		}
		if (i != 2) {
			cout << "--------------------\n";	
		}
	}
}

bool checkWinner() {
	if (grid[0][0] && grid[0][0] == grid[0][1] && grid[0][0] == grid[0][2]) {
		return true;
	} else if (grid[1][0] && grid[1][0] == grid[1][1] && grid[1][0] == grid[1][2]) {
		return true;
	} else if (grid[2][0] && grid[2][0] == grid[2][1] && grid[2][0] == grid[2][2]) {
		return true;
	} else if (grid[0][0] && grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) {
		return true;
	} else if (grid[0][2] && grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) {
		return true;
	}
	return false;
}
