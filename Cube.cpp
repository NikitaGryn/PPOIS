#include "Cube.h"

using namespace std;

Cube::Cube() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sides[Side::Down][i][j] = Color::White;
			sides[Side::Up][i][j] = Color::Yellow;
			sides[Side::Front][i][j] = Color::Green;
			sides[Side::Left][i][j] = Color::Red;
			sides[Side::Right][i][j] = Color::Orange;
			sides[Side::Back][i][j] = Color::Blue;
		}
	}
}

void Cube::Shuffle() {
	srand(time(NULL));
	int numberOfMoves = 10 + rand() % 20;
	int move;
	char moveName;
	bool isStroke;
	for (int i = 0; i < numberOfMoves; i++) {
		move = rand() % 6;
		switch (move) {
		case Moves::F:
			moveName = 'f';
			break;
		case Moves::U:
			moveName = 'u';
			break;
		case Moves::D:
			moveName = 'd';
			break;
		case Moves::L:
			moveName = 'l';
			break;
		case Moves::R:
			moveName = 'r';
			break;
		case Moves::B:
			moveName = 'b';
			break;
		}
		isStroke = rand() % 2;
		this->MakeMove(Moves(move), isStroke);
	}
}

Cube::Cube(string str) {
	ifstream file(str);
	initFromFile(Side::Up, file);
	initFromFile(Side::Left, file);
	initFromFile(Side::Front, file);
	initFromFile(Side::Right, file);
	initFromFile(Side::Back, file);
	initFromFile(Side::Down, file);
	file.close();
}

void Cube::initFromFile(Side side, ifstream& file) {
	int out;
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			file >> out;
			sides[side][j][k] = (Color)out;
		}
	}
}

string Cube::ToString() {
	string str = "";
	for (int i = 0; i < 3; i++) {
		str += "      ";
		for (int j = 0; j < 3; j++) {
			str += getColor(Side::Up, i, j);
		}
		str += '\n';
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 12; j++) {
			if (j > 8) {
				str += getColor(Side::Back, i, j - 9);
				continue;
			}
			if (j > 5) {
				str += getColor(Side::Right, i, j - 6);
				continue;
			}
			if (j > 2) {
				str += getColor(Side::Front, i, j - 3);
				continue;
			}
			str += getColor(Side::Left, i, j);
		}
		str += '\n';
	}
	for (int i = 0; i < 3; i++) {
		str += "      ";
		for (int j = 0; j < 3; j++) {
			str += getColor(Side::Down, i, j);
		}
		str += '\n';
	}
	return str;
}

void Cube::MakeMove(Moves move, bool stroke) {
	switch (move) {
	case Moves::U:
		swapAdjacentZ(Side::Up);
		if (stroke) {
			reverseTurn(Side::Up);
			inverseAdjacentZ(Side::Up);
			return;
		}
		turn(Side::Up);
		break;
	case Moves::D:
		swapAdjacentZ(Side::Down);
		if (stroke) {
			reverseTurn(Side::Down);
			return;
		}
		inverseAdjacentZ(Side::Down);
		turn(Side::Down);
		break;
	case Moves::R:
		swapAdjacentX(Side::Right);
		if (stroke) {
			reverseTurn(Side::Right);
			inverseAdjacentX(Side::Right);
			return;
		}
		turn(Side::Right);
		break;
	case Moves::L:
		swapAdjacentX(Side::Left);
		if (stroke) {
			reverseTurn(Side::Left);
			return;
		}
		inverseAdjacentX(Side::Left);
		turn(Side::Left);
		break;
	case Moves::F:
		swapAdjacentY(Side::Front);
		if (stroke) {
			reverseTurn(Side::Front);
			inverseAdjacentY(Side::Front);
			return;
		}
		turn(Side::Front);
		break;
	case Moves::B:
		swapAdjacentY(Side::Back);
		if (stroke) {
			reverseTurn(Side::Back);
			return;
		}
		inverseAdjacentY(Side::Back);
		turn(Side::Back);
		break;
	}
}

bool Cube::IsCubeSolved() {
	for (int i = 0; i < 6; i++) {
		if (!isFaceSolved(i))
			return false;
	}
	return true;
}

void Cube::turn(Side side) {
	transpose(side);
	swapCollumns(side);
}

void Cube::reverseTurn(Side side) {
	transpose(side);
	swapRows(side);
}

bool Cube::isFaceSolved(int side) {
	int color = side;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sides[side][i][j] != color)
				return false;
		}
	}
	return true;
}

string Cube::getColor(Side side, int i, int j) {
	int number = sides[side][i][j];
	return to_string(number) + " ";
}

void Cube::transpose(Side side) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j > i) continue;
			swapColors(sides[side][i][j], sides[side][j][i]);
		}
	}
}

void Cube::swapColors(Color& color1, Color& color2) {
	Color temp = color1;
	color1 = color2;
	color2 = temp;
}

void Cube::swapCollumns(Side side) {
	for (int i = 0; i < 3; i++) {
		swapElement(sides[side][i][0], sides[side][i][2]);
	}
}

void Cube::swapRows(Side side) {
	for (int i = 0; i < 3; i++) {
		swapElement(sides[side][0][i], sides[side][2][i]);
	}
}

void Cube::swapElement(Color& color1, Color& color2) {
	Color temp = color1;
	color1 = color2;
	color2 = temp;
}

void Cube::swapAdjacentZ(Side side) {
	int offset = (side == Side::Up) ? 0 : 2;
	Color temp[3];
	for (int i = 0; i < 3; i++) {
		temp[i] = sides[Side::Left][offset][i];
		sides[Side::Left][offset][i] = sides[Side::Front][offset][i];
		sides[Side::Front][offset][i] = sides[Side::Right][offset][i];
		sides[Side::Right][offset][i] = sides[Side::Back][offset][i];
		sides[Side::Back][offset][i] = temp[i];
	}
}

void Cube::inverseAdjacentZ(Side side) {
	int offset = (side == Side::Up) ? 0 : 2;
	for (int i = 0; i < 3; i++) {
		swapElement(sides[Side::Front][offset][i], sides[Side::Back][offset][i]);
		swapElement(sides[Side::Left][offset][i], sides[Side::Right][offset][i]);
	}
}

void Cube::swapAdjacentY(Side side) {
	int offset = (side == Side::Front) ? 2 : 0;
	Color temp[3];
	for (int i = 0; i < 3; i++) {
		temp[i] = sides[Side::Left][i][offset];
		sides[Side::Left][i][offset] = sides[Side::Down][2 - offset][i];
		sides[Side::Down][2 - offset][i] = sides[Side::Right][2 - i][abs(offset - 2)];
		sides[Side::Right][2 - i][abs(offset - 2)] = sides[Side::Up][offset][2 - i];
		sides[Side::Up][offset][2 - i] = temp[i];
	}
}

void Cube::inverseAdjacentY(Side side) {
	int offset = (side == Side::Front) ? 2 : 0;
	for (int i = 0; i < 3; i++) {
		swapElement(sides[Side::Left][i][offset], sides[Side::Right][2 - i][abs(offset - 2)]);
		swapElement(sides[Side::Down][2 - offset][i], sides[Side::Up][offset][2 - i]);
	}
}

void Cube::swapAdjacentX(Side side) {
	int offset = (side == Side::Right) ? 2 : 0;
	Color temp[3];
	for (int i = 0; i < 3; i++) {
		temp[i] = sides[Side::Up][i][offset];
		sides[Side::Up][i][offset] = sides[Side::Front][i][offset];
		sides[Side::Front][i][offset] = sides[Side::Down][i][offset];
		sides[Side::Down][i][offset] = sides[Side::Back][2 - i][abs(offset - 2)];
		sides[Side::Back][2 - i][abs(offset - 2)] = temp[i];
	}
}

void Cube::inverseAdjacentX(Side side) {
	int offset = (side == Side::Right) ? 2 : 0;
	for (int i = 0; i < 3; i++) {
		swapElement(sides[Side::Up][i][offset], sides[Side::Down][i][offset]);
		swapElement(sides[Side::Front][i][offset], sides[Side::Back][2 - i][abs(offset - 2)]);
	}
}

