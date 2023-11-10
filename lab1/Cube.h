#pragma once
#include <string>
#include <fstream>

enum Color { Yellow, Green, Blue, White, Orange, Red };
enum Side { Up, Front, Back, Down, Right, Left };
enum Moves { U, D, R, L, F, B };

class Cube {
public:
	Cube();
	void Shuffle();
	Cube(std::string str);
	std::string ToString();
	void MakeMove(Moves move, bool stroke = false);
	bool IsCubeSolved();
private:
	void initFromFile(Side side, std::ifstream& file); 
	void turn(Side side);
	void reverseTurn(Side side);
	bool isFaceSolved(int side);
	std::string getColor(Side side, int i, int j);
	void transpose(Side side);
	void swapColors(Color& color1, Color& color2);
	void swapCollumns(Side side);
	void swapRows(Side side);
	void swapElement(Color& color1, Color& color2);
	void swapAdjacentZ(Side side);
	void inverseAdjacentZ(Side side);
	void swapAdjacentY(Side side);
	void inverseAdjacentY(Side side);
	void swapAdjacentX(Side side);
	void inverseAdjacentX(Side side);
	Color sides[6][3][3];
	void UpMove(bool stroke);
	void DownMove(bool stroke);
	void RightMove(bool stroke);
	void LeftMove(bool stroke);
	void FrontMove(bool stroke);
	void BackMove(bool stroke);
};

