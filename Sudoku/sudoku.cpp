#include<iostream>
#include<sstream>
#include<fstream>
#include "create.h"
#include "solve.h"

using namespace std;
ofstream out("sudoku.txt");
char result[163000001];
int r_tag = 0;

int main(int argc, char * argv[]) {
	int sudoku[9][9] = { 0 };
	int num = 0;
	int x = 0, y = 0, X = 0, Y = 0;
	int j = 0;
	int others[4];
	if (argc != 3) {
		cout << "参数错误\n"; exit(1);
	}
	if (strcmp(argv[1], "-c") == 0) {
		if (atoi(argv[2]) < 1 || atoi(argv[2]) > 1000000) {
			cout << "参数错误\n"; exit(1);
		}
		num = atoi(argv[2]);
		if (!out.is_open()) {
			cout << "打开文件时出错\n"; exit(1);
		}
		for (x = 1; x <= 7; x++)
			for (y = x + 1; y <= 8; y++)
				for (X = 1; X <= 7; X++)
					for (Y = X + 1; Y <= 8; Y++)
						if (X != x&&X != y&&Y != x&&Y != y) {
							for (int i = 1; i < 9; i++) {
								if (X != i&&x != i&&Y != i&&y != i) {
									if (i == 6)
										others[j++] = 9;
									else
										others[j++] = i;
								}
								if (j == 4) {
									j = 0;
									break;
								}
							}
							if (X == 6)X = 9; if (Y == 6)Y = 9; if (x == 6)x = 9; if (y == 6)y = 9;
							transform(x, y, X, Y, others, num, result, r_tag); num -= 5184;
							transform(y, x, X, Y, others, num, result, r_tag); num -= 5184;
							transform(x, y, Y, X, others, num, result, r_tag); num -= 5184;
							transform(y, x, Y, X, others, num, result, r_tag); num -= 5184;
							if (num <= 0) {
								out << result;
								cout << "输出完成\n"; exit(0);
							}
						}
	}
	else if ((strcmp(argv[1], "-s") == 0)) {
		ifstream in(argv[2]);
		char temp = ' ';
		if (!in.is_open()) {
			cout << "打开文件时出错\n"; exit(1);
		}
		if (!out.is_open()) {
			cout << "打开文件时出错\n"; exit(1);
		}
		do {
			while ('0' > temp||temp > '9')
				in >> temp; 
			sudoku[0][0] = temp - '0';
			j = 1;
			for (int i = 0; i < 9; i++) {
				do {
					in >> temp;
					if (in.eof()) break;
					sudoku[i][j++] = temp - '0';
				} while (j < 9);
				j = 0;
			}
			if (in.eof())break;
			solve(sudoku, result, r_tag);
			in >> temp;
		} while (!in.eof());
		out << result;
		cout << "输出完成\n"; exit(0);
	}
	else
		cout << "参数错误\n"; exit(1);
	system("pause");
	return 0;
}

