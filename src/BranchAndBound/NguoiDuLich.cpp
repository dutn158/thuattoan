/*
 * NguoiDuLich.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: TranDu
 */

#include <iostream>
using namespace std;

#define MAX 500

#define N 7

int Board[N + 1][N + 1];
int DaDi[N + 1];
int ChiPhi[N + 1];
int best[N + 1];
int Min = MAX;
int tpxp;
int FREE[N+1];

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Board[i][j] = MAX;
		}
		DaDi[i] = 0;
		ChiPhi[i] = 0;
		FREE[i] = 0;
	}

	Board[1][3] = 14;
	Board[1][5] = 6;
	Board[1][6] = 7;
	Board[2][3] = 15;
	Board[2][4] = 9;
	Board[2][5] = 1;
	Board[2][7] = 9;
	Board[3][1] = 3;
	Board[3][3] = 15;
	Board[3][4] = 9;
	Board[3][5] = 1;
	Board[3][6] = 9;
	Board[4][2] = 12;
	Board[4][3] = 6;
	Board[4][5] = 5;
	Board[4][6] = 11;
	Board[4][7] = 3;
	Board[5][1] = 8;
	Board[5][3] = 7;
	Board[5][7] = 7;
	Board[6][2] = 1;
	Board[6][3] = 4;
	Board[6][5] = 15;
	Board[6][7] = 9;
	Board[7][1] = 2;
	Board[7][2] = 16;
	Board[7][4] = 8;
	Board[7][6] = 3;

	tpxp = 1;
	FREE[tpxp] = 1;
	DaDi[1] = tpxp;
	ChiPhi[1] = 0;
}

void print(int a[][N + 1], int n) {
	cout << endl << "====================>>" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "<<====================" << endl;
}

void print(int a[], int n) {
	cout << endl << "====================>>" << endl;
	for (int i = 1; i <= n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl << "<<====================" << endl;
}

void Try(int i) {
	for (int k = 1; k <= N; k++) {
		if (FREE[k] == 0) {
			FREE[k] = 1;
			DaDi[i] = k;
			ChiPhi[i] = ChiPhi[i - 1] + Board[DaDi[i - 1]][DaDi[i]];

			if (i == N) {
				if (ChiPhi[i] + Board[DaDi[i]][DaDi[tpxp]] < Min) {
					Min = ChiPhi[i] + Board[DaDi[i]][DaDi[tpxp]];
					for (int m = 1; m <= N; m++) {
						best[m] = DaDi[m];
					}
				}
			} else {
				if (ChiPhi[i] < Min) {
					Try(i + 1);
				}
			}

			ChiPhi[i] = 0;
			DaDi[i] = 0;
			FREE[k] = 0;
		}
	}
}

int main(int argc, char **argv) {
	init();

	print(Board, N);

	Try(2);

	print(best, N);
	cout << endl << "Chi Phi: " << Min << endl;

}
