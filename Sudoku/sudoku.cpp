#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;
ofstream out("sudoku.txt");
char result[163000001];
int r_tag = 0;

void transform(int sudoku[][9], int x, int y, int X, int Y, int* others, int num) {
	int sudoku_temp[9][9];
	int x1, x2, x3, y1, y2, y3;
	if (num <= 0)
		return;
	sudoku[0][0] = sudoku[6][1] = sudoku[3][2] = sudoku[2][3] = sudoku[8][4] = sudoku[5][5] = sudoku[1][6] = sudoku[7][7] = sudoku[4][8] = 6;
	sudoku[1][0] = sudoku[7][1] = sudoku[4][2] = sudoku[0][3] = sudoku[6][4] = sudoku[3][5] = sudoku[2][6] = sudoku[8][7] = sudoku[5][8] = x;
	sudoku[2][0] = sudoku[8][1] = sudoku[5][2] = sudoku[1][3] = sudoku[7][4] = sudoku[4][5] = sudoku[0][6] = sudoku[6][7] = sudoku[3][8] = y;
	sudoku[3][0] = sudoku[0][1] = sudoku[6][2] = sudoku[5][3] = sudoku[2][4] = sudoku[8][5] = sudoku[4][6] = sudoku[1][7] = sudoku[7][8] = X;
	sudoku[4][0] = sudoku[1][1] = sudoku[7][2] = sudoku[3][3] = sudoku[0][4] = sudoku[6][5] = sudoku[5][6] = sudoku[2][7] = sudoku[8][8] = others[0];
	sudoku[5][0] = sudoku[2][1] = sudoku[8][2] = sudoku[4][3] = sudoku[1][4] = sudoku[7][5] = sudoku[3][6] = sudoku[0][7] = sudoku[6][8] = others[1];
	sudoku[6][0] = sudoku[3][1] = sudoku[0][2] = sudoku[8][3] = sudoku[5][4] = sudoku[2][5] = sudoku[7][6] = sudoku[4][7] = sudoku[1][8] = Y;
	sudoku[7][0] = sudoku[4][1] = sudoku[1][2] = sudoku[6][3] = sudoku[3][4] = sudoku[0][5] = sudoku[8][6] = sudoku[5][7] = sudoku[2][8] = others[2];
	sudoku[8][0] = sudoku[5][1] = sudoku[2][2] = sudoku[7][3] = sudoku[4][4] = sudoku[1][5] = sudoku[6][6] = sudoku[3][7] = sudoku[0][8] = others[3];
	memcpy(sudoku_temp, sudoku, sizeof(sudoku_temp));
	for (x1 = 0; x1 < 2; x1++) {
		for (x2 = 0; x2 < 6; x2++) {
			for (x3 = 0; x3 < 6; x3++) {
				for (y1 = 0; y1 < 2; y1++) {
					for (y2 = 0; y2 < 6; y2++) {
						for (y3 = 0; y3 < 6; y3++) {
							if (x1 == 1)
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[1][k], sudoku_temp[2][k]);
							switch (x2) {
							case 1:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[4][k], sudoku_temp[5][k]);
								break;
							case 2:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[3][k], sudoku_temp[4][k]);
								break;
							case 3:
								for (int k = 0; k < 9; k++) {
									swap(sudoku_temp[3][k], sudoku_temp[4][k]);
									swap(sudoku_temp[4][k], sudoku_temp[5][k]);
								}
								break;
							case 4:
								for (int k = 0; k < 9; k++) {
									swap(sudoku_temp[4][k], sudoku_temp[5][k]);
									swap(sudoku_temp[3][k], sudoku_temp[4][k]);
								}
								break;
							case 5:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[3][k], sudoku_temp[5][k]);
								break;
							}
							switch (x3) {
							case 1:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[7][k], sudoku_temp[8][k]);
								break;
							case 2:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[6][k], sudoku_temp[7][k]);
								break;
							case 3:
								for (int k = 0; k < 9; k++) {
									swap(sudoku_temp[6][k], sudoku_temp[7][k]);
									swap(sudoku_temp[7][k], sudoku_temp[8][k]);
								}
								break;
							case 4:
								for (int k = 0; k < 9; k++) {
									swap(sudoku_temp[7][k], sudoku_temp[8][k]);
									swap(sudoku_temp[6][k], sudoku_temp[7][k]);
								}
								break;
							case 5:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[6][k], sudoku_temp[8][k]);
								break;
							}
							if (y1 == 1)
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[k][1], sudoku_temp[k][2]);
							switch (y2) {
							case 1:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[k][4], sudoku_temp[k][5]);
								break;
							case 2:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[k][3], sudoku_temp[k][4]);
								break;
							case 3:
								for (int k = 0; k < 9; k++) {
									swap(sudoku_temp[k][3], sudoku_temp[k][4]);
									swap(sudoku_temp[k][4], sudoku_temp[k][5]);
								}
								break;
							case 4:
								for (int k = 0; k < 9; k++) {
									swap(sudoku_temp[k][4], sudoku_temp[k][5]);
									swap(sudoku_temp[k][3], sudoku_temp[k][4]);
								}
								break;
							case 5:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[k][3], sudoku_temp[k][5]);
								break;
							}
							switch (y3) {
							case 1:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[k][7], sudoku_temp[k][8]);
								break;
							case 2:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[k][6], sudoku_temp[k][7]);
								break;
							case 3:
								for (int k = 0; k < 9; k++) {
									swap(sudoku_temp[k][6], sudoku_temp[k][7]);
									swap(sudoku_temp[k][7], sudoku_temp[k][8]);
								}
								break;
							case 4:
								for (int k = 0; k < 9; k++) {
									swap(sudoku_temp[k][7], sudoku_temp[k][8]);
									swap(sudoku_temp[k][6], sudoku_temp[k][7]);
								}
								break;
							case 5:
								for (int k = 0; k < 9; k++)
									swap(sudoku_temp[k][6], sudoku_temp[k][8]);
								break;
							}
							for (int i = 0; i < 9; i++) {
								for (int j = 0; j < 9; j++) {
									result[r_tag++] = char(sudoku_temp[i][j] + '0');
									if (j == 8)
										result[r_tag++] = '\n';
									else
										result[r_tag++] = ' ';
								}
							}
							result[r_tag++] = '\n';
							memcpy(sudoku_temp, sudoku, sizeof(sudoku_temp));
							num--;
							if (num == 0)
								return;
						}
					}
				}
			}
		}
	}
	return;
}

bool isequal(int sudoku[][9], int m, int n, int i) {
	int temp = 0;
	if (sudoku[m][n] == i)
		return true;
	temp = sudoku[m][n] / 10;
	if (i == temp % 10)
		return true;
	return false;
}

int feasible(int sudoku[][9], int x, int y, int i) {
	int m = 0, n = 0;
	switch (x / 3 * 3 + y / 3) {
	case 0:
		for (m = 0; m < 3; m++)
			for (n = 0; n < 3; n++)
				if (isequal(sudoku, m, n, i))return 0;
		break;
	case 1:
		for (m = 0; m < 3; m++)
			for (n = 3; n < 6; n++)
				if (isequal(sudoku, m, n, i))return 0;
		break;
	case 2:
		for (m = 0; m < 3; m++)
			for (n = 6; n < 9; n++)
				if (isequal(sudoku, m, n, i))return 0;
		break;
	case 3:
		for (m = 3; m < 6; m++)
			for (n = 0; n < 3; n++)
				if (isequal(sudoku, m, n, i))return 0;
		break;
	case 4:
		for (m = 3; m < 6; m++)
			for (n = 3; n < 6; n++)
				if (isequal(sudoku, m, n, i))return 0;
		break;
	case 5:
		for (m = 3; m < 6; m++)
			for (n = 6; n < 9; n++)
				if (isequal(sudoku, m, n, i))return 0;
		break;
	case 6:
		for (m = 6; m < 9; m++)
			for (n = 0; n < 3; n++)
				if (isequal(sudoku, m, n, i))return 0;
		break;
	case 7:
		for (m = 6; m < 9; m++)
			for (n = 3; n < 6; n++)
				if (isequal(sudoku, m, n, i))return 0;
		break;
	case 8:
		for (m = 6; m < 9; m++)
			for (n = 6; n < 9; n++)
				if (isequal(sudoku, m, n, i))return 0;
		break;
	}
	return 1;
}


void solve(int sudoku_s[][9]) {
	int sudoku[9][9];
	int st = 0;
	memcpy(sudoku, sudoku_s, sizeof(sudoku));
	int x = 0, y = 0, i = 0, j = 0, m = 0, n = 0, tag = 1;
	while (x != 9 && y != -1) {
		if (0 <= x&&x <= 8 && 0 <= y&&y <= 8 && sudoku[x][y] == 0) {
			for (i = 1; i <= 9; i++) {
				tag = feasible(sudoku, x, y, i);
				if (tag == 0) {
					tag = 1;
					continue;
				}
				for (j = 0; j < 9; j++) {
					if (sudoku[x][j] == i) break;
					if (sudoku[j][y] == i) break;
					if (isequal(sudoku, x, j, i))break;
					if (isequal(sudoku, j, y, i))break;
				}
				if (j != 9)continue;
				sudoku[x][y] = (sudoku[x][y] * 10 + i);
			}
			sudoku[x][y] = sudoku[x][y] * 10;
			if (sudoku[x][y] == 0) {
				st = 1;
				y--;
				if (y == -1) {
					x--; y = 8;
				}
			}
			else {
				st = 0;
				y++;
				if (y == 9) {
					x++; y = 0;
				}
			}
		}
		else if (0 <= x&&x <= 8 && 0 <= y&&y <= 8 && sudoku[x][y] < 100 && sudoku[x][y]>9) {
			sudoku[x][y] = 0;
			st = 1;
			y--;
			if (y == -1) {
				x--; y = 8;
			}
		}
		else if (0 <= x&&x <= 8 && 0 <= y&&y <= 8 && sudoku[x][y] > 100) {
			sudoku[x][y] = (sudoku[x][y] / 100) * 10;
			st = 0;
			y++;
			if (y == 9) {
				x++; y = 0;
			}
		}
		else {
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
							transform(sudoku, x, y, X, Y, others, num); num -= 5184;
							transform(sudoku, y, x, X, Y, others, num); num -= 5184;
							transform(sudoku, x, y, Y, X, others, num); num -= 5184;
							transform(sudoku, y, x, Y, X, others, num); num -= 5184;
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
			solve(sudoku);
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

