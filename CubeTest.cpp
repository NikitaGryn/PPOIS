#include "pch.h"
#include <Windows.h>
#include <string>
#include "CppUnitTest.h"
#include "../Rubick's Cube/Cube.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace CubeTest
{
	TEST_CLASS(CubeTest)
	{
	public:
		
		TEST_METHOD(InitialCube) {
			Cube cube;
			string expected = "\
      0 0 0 \n\
      0 0 0 \n\
      0 0 0 \n\
5 5 5 1 1 1 4 4 4 2 2 2 \n\
5 5 5 1 1 1 4 4 4 2 2 2 \n\
5 5 5 1 1 1 4 4 4 2 2 2 \n\
      3 3 3 \n\
      3 3 3 \n\
      3 3 3 \n";
			Assert::AreEqual(expected, cube.ToString());
		}

		TEST_METHOD(IsSolved) {
			Cube cube;
			Assert::AreEqual(true, cube.IsCubeSolved());
		}

		TEST_METHOD(Shuffle) {
			Cube cube;
			cube.Shuffle();
			Assert::AreEqual(false, cube.IsCubeSolved());
		}

		TEST_METHOD(R) {
			Cube cube;
			cube.MakeMove(Moves::R);
			cube.MakeMove(Moves::R, true);
			Assert::AreEqual(true, cube.IsCubeSolved());
		}

		TEST_METHOD(L) {
			Cube cube;
			cube.MakeMove(Moves::L);
			cube.MakeMove(Moves::L, true);
			Assert::AreEqual(true, cube.IsCubeSolved());
		}

		TEST_METHOD(U) {
			Cube cube;
			cube.MakeMove(Moves::U);
			cube.MakeMove(Moves::U, true);
			Assert::AreEqual(true, cube.IsCubeSolved());
		}

		TEST_METHOD(F) {
			Cube cube;
			cube.MakeMove(Moves::F);
			cube.MakeMove(Moves::F, true);
			Assert::AreEqual(true, cube.IsCubeSolved());
		}

		TEST_METHOD(B) {
			Cube cube;
			cube.MakeMove(Moves::B);
			cube.MakeMove(Moves::B, true);
			Assert::AreEqual(true, cube.IsCubeSolved());
		}

		TEST_METHOD(D) {
			Cube cube;
			cube.MakeMove(Moves::D);
			cube.MakeMove(Moves::D, true);
			Assert::AreEqual(true, cube.IsCubeSolved());
		}

		TEST_METHOD(OneMove) {
			Cube cube;
			cube.MakeMove(Moves::R);
			Assert::AreEqual(false, cube.IsCubeSolved());
		}

		TEST_METHOD(FromFile) {
			Cube cube("D:\input.txt");
			string expected = "\
      0 5 2 \n\
      5 0 3 \n\
      4 5 3 \n\
4 3 3 2 2 4 1 1 3 5 1 1 \n\
4 5 3 2 1 0 2 4 5 0 2 1 \n\
2 2 2 0 4 0 1 1 3 5 0 0 \n\
      5 3 5 \n\
      4 3 0 \n\
      4 4 1 \n";
			Assert::AreEqual(expected, cube.ToString());
		}
	};
}
