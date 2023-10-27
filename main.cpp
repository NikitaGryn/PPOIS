#include <iostream>
#include "Cube.h"

using namespace std;

int main() {
	
	Cube cube("input.txt");
	cout << cube.ToString() << endl;
	cube.Shuffle();
	cout << cube.ToString() << endl;
	bool stroke;
	Moves move;
	char input[2];
	while (true) {
		cout << "1. u, 2. f, 3. b, 4. d, 5. r, 6. l" << endl;
		cout << "t or f(stroke)" << endl;
		cin >> input[0] >> input[1];
		switch (input[0]) {
		case 'u':
			move = Moves::U;
			break;
		case 'f':
			move = Moves::F;
			break;
		case 'b':
			move = Moves::B;
			break;
		case 'd':
			move = Moves::D;
			break;
		case 'r':
			move = Moves::R;
			break;
		case 'l':
			move = Moves::L;
			break;
		default:
			move = Moves::U;
		}
		switch (input[1]) {
		case 't':
			stroke = true;
			break;
		case 'f':
			stroke = false;
			break;
		default:
			stroke = false;
			break;
		}
		cube.MakeMove(Moves(move), stroke);
		cout << cube.ToString() << endl;
	}
	cout << "Is solved: " << cube.IsCubeSolved() << endl;
	return 0;
}