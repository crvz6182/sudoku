#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Sudoku/create.h"
#include "../Sudoku/solve.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_solve)
		{
			// TODO: 在此输入测试代码
			char result[200];
			int r_tag = 0;
			for (int i = 0; i < 200; i++) {
				result[i] = 0;
			}
			char answer[200] = "6 3 4 1 5 7 2 9 8\n1 5 7 2 9 8 6 3 4\n2 9 8 6 3 4 1 5 7\n3 4 6 5 7 1 9 8 2\n5 7 1 9 8 2 3 4 6\n9 8 2 3 4 6 5 7 1\n4 6 3 7 1 5 8 2 9\n7 1 5 8 2 9 4 6 3\n8 2 9 4 6 3 7 1 5\n\n";
			int sudoku[9][9] = {
				6,3,0,1,5,0,2,9,8,
				0,5,0,2,9,0,6,0,4,
				2,0,8,6,3,0,1,5,7,
				3,4,0,5,7,1,0,8,2,
				0,7,1,9,0,2,3,0,6,
				9,8,2,0,4,0,5,7,0,
				4,6,3,7,1,5,8,2,9,
				7,1,5,0,2,0,4,0,3,
				8,2,0,4,6,3,7,1,5 };
			solve(sudoku, result, r_tag);
			Assert::AreEqual(result, answer);
		}
		TEST_METHOD(Test_in_area)
		{
			// TODO: 在此输入测试代码
			bool result;
			int sudoku[9][9] = {
				6,3,4,1,5,7,2,9,8,
				1,5,7,2,9,8,6,3,4,
				2,9,8,6,3,4,1,5,7,
				3,4,6,5,7,1,9,8,2,
				5,7,1,9,8,2,3,4,6,
				9,8,2,3,4,6,5,7,1,
				4,6,3,7,1,5,8,2,9,
				7,1,5,8,2,9,4,6,3,
				8,2,9,4,6,3,7,1,5 };
			result = in_area(sudoku, 2, 3, 5);
			Assert::AreEqual(result, true);
		}
		TEST_METHOD(Test_transform)
		{
			// TODO: 在此输入测试代码
			char answer[1000]="6 3 4 1 5 8 2 7 9\n1 5 8 2 7 9 6 3 4\n2 7 9 6 3 4 1 5 8\n3 4 6 5 8 1 7 9 2\n5 8 1 7 9 2 3 4 6\n7 9 2 3 4 6 5 8 1\n4 6 3 8 1 5 9 2 7\n8 1 5 9 2 7 4 6 3\n9 2 7 4 6 3 8 1 5\n\n6 3 4 1 5 8 2 9 7\n1 5 8 2 7 9 6 4 3\n2 7 9 6 3 4 1 8 5\n3 4 6 5 8 1 7 2 9\n5 8 1 7 9 2 3 6 4\n7 9 2 3 4 6 5 1 8\n4 6 3 8 1 5 9 7 2\n8 1 5 9 2 7 4 3 6\n9 2 7 4 6 3 8 5 1\n\n6 3 4 1 5 8 7 2 9\n1 5 8 2 7 9 3 6 4\n2 7 9 6 3 4 5 1 8\n3 4 6 5 8 1 9 7 2\n5 8 1 7 9 2 4 3 6\n7 9 2 3 4 6 8 5 1\n4 6 3 8 1 5 2 9 7\n8 1 5 9 2 7 6 4 3\n9 2 7 4 6 3 1 8 5\n\n";
			char result[1000];
			int r_tag = 0;
			int others[4] = { 5,7,8,9 };
			for (int i = 0; i < 1000; i++) {
				result[i] = 0;
			}
			transform(1, 2, 3, 4, others, 3, result, r_tag);
			Assert::AreEqual(result, answer);
		}
	};
}