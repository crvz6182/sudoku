#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

bool in_area(int sudoku[][9], int x, int y, int i) { //判断某个数是否已经在x,y所在宫内
	int m = 0, n = 0;
	switch (x / 3 * 3 + y / 3) {
	case 0:
		for (m = 0; m < 3; m++)
			for (n = 0; n < 3; n++)
				if (sudoku[m][n] == i)return true;
		break;
	case 1:
		for (m = 0; m < 3; m++)
			for (n = 3; n < 6; n++)
				if (sudoku[m][n] == i)return true;
		break;
	case 2:
		for (m = 0; m < 3; m++)
			for (n = 6; n < 9; n++)
				if (sudoku[m][n] == i)return true;
		break;
	case 3:
		for (m = 3; m < 6; m++)
			for (n = 0; n < 3; n++)
				if (sudoku[m][n] == i)return true;
		break;
	case 4:
		for (m = 3; m < 6; m++)
			for (n = 3; n < 6; n++)
				if (sudoku[m][n] == i)return true;
		break;
	case 5:
		for (m = 3; m < 6; m++)
			for (n = 6; n < 9; n++)
				if (sudoku[m][n] == i)return true;
		break;
	case 6:
		for (m = 6; m < 9; m++)
			for (n = 0; n < 3; n++)
				if (sudoku[m][n] == i)return true;
		break;
	case 7:
		for (m = 6; m < 9; m++)
			for (n = 3; n < 6; n++)
				if (sudoku[m][n] == i)return true;
		break;
	case 8:
		for (m = 6; m < 9; m++)
			for (n = 6; n < 9; n++)
				if (sudoku[m][n] == i)return true;
		break;
	}
	return false;
}

void solve(int sudoku_s[][9], char* result, int &r_tag) {
	int sudoku[9][9];
	int list[9][9][9];
	int list_tag[9][9];
	int st = 0;
	memcpy(sudoku, sudoku_s, sizeof(sudoku));
	int x = 0, y = 0, i = 0, j = 0, m = 0, n = 0;
	for (int p = 0; p < 9; p++)
		for (int q = 0; q < 9; q++) {
			if (sudoku[p][q] == 0)
				list_tag[p][q] = -1;
			else
				list_tag[p][q] = -2;
			for (int r = 0; r < 9; r++) {
				list[p][q][r] = 0;
			}
		}
	while (x != 9 && y != -1) {
		if (0 <= x&&x <= 8 && 0 <= y&&y <= 8 && sudoku[x][y] == 0) {
			for (i = 1; i <= 9; i++) {
				if (in_area(sudoku, x, y, i))continue;
				for (j = 0; j < 9; j++) {
					if (sudoku[x][j] == i) break;
					if (sudoku[j][y] == i) break;
				}
				if (j != 9)continue;
				list[x][y][++list_tag[x][y]] = i;
			}
			if (list_tag[x][y] == -1) {
				st = 1;
				y--;
				if (y == -1) {
					x--; y = 8;
				}
			}
			else {
				sudoku[x][y] = list[x][y][list_tag[x][y]];
				st = 0;
				y++;
				if (y == 9) {
					x++; y = 0;
				}
			}
		}
		else {
			if (list_tag[x][y] == -2) {
				switch (st) {
				case 0:
					y++;
					if (y == 9) {
						x++; y = 0;
					}break;
				case 1:
					y--;
					if (y == -1) {
						x--; y = 8;
					}
					break;
				}
			}
			else {
				if (list_tag[x][y] == 0) {
					sudoku[x][y] = 0;
					list[x][y][0] = 0;
					list_tag[x][y] = -1;
					st = 1;
					y--;
					if (y == -1) {
						x--; y = 8;
					}
				}
				else {
					list[x][y][list_tag[x][y]] = 0;
					sudoku[x][y] = list[x][y][--list_tag[x][y]];
					st = 0;
					y++;
					if (y == 9) {
						x++; y = 0;
					}
				}
			}
		}
		if (y == -1) {
			cout << "无解\n"; exit(1);
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			result[r_tag++] = char(sudoku[i][j] + '0');
			if (j == 8)
				result[r_tag++] = '\n';
			else
				result[r_tag++] = ' ';
		}
	}
	result[r_tag++] = '\n';
	return;
}