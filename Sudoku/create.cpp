#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;
void transform(int x, int y, int X, int Y, int* others, int num, char *result, int &r_tag) {
	int sudoku[9][9];
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