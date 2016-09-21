#include <iostream>
using namespace std;

#define N 3
#define MAX 500

int Board[N + 1][N + 1];
int Tho[N + 1];
int CongViec[N + 1];
int ChiPhi[N + 1];
int FreeTho[N + 1];
int FreeCongViec[N + 1];
int best[N+1];
int bestTho[N + 1];
int bestCongViec[N + 1];
int Min = MAX;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Board[i][j] = 0;
		}
		FreeTho[i] = 0;
		FreeCongViec[i] = 0;
		ChiPhi[i] = 0;
	}
	ChiPhi[0] = 0;

	Board[1][1] = 4;
	Board[1][2] = 5;
	Board[1][3] = 2;
	Board[1][4] = 1;
	Board[1][5] = 7;

	Board[2][1] = 1;
	Board[2][2] = 3;
	Board[2][3] = 5;
	Board[2][4] = 7;
	Board[2][5] = 4;

	Board[3][1] = 2;
	Board[3][2] = 3;
	Board[3][3] = 7;
	Board[3][4] = 1;
	Board[3][5] = 4;

//	Board[4][1] = 3;
//	Board[4][2] = 4;
//	Board[4][3] = 7;
//	Board[4][4] = 1;
//	Board[4][5] = 2;
//
//	Board[5][1] = 2;
//	Board[5][2] = 4;
//	Board[5][3] = 4;
//	Board[5][4] = 2;
//	Board[5][5] = 7;

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
		if (FreeCongViec[k] == 0) {
			FreeCongViec[k] = 1;
			Tho[i] = k;
			ChiPhi[i] = ChiPhi[i-1] + Board[Tho[i-1]][Tho[i]];

			if (i == N) {
				if (ChiPhi[i] < Min) {
					Min = ChiPhi[i];
					for (int m = 0; m <= N; m++) {
						best[m] = Tho[m];
					}
				}
			} else {
				if (ChiPhi[i] < Min) {
					Try(i+1);
				}
			}


			FreeCongViec[k] = 0;
		}
	}
}

int main(int argc, char **argv) {
	init();
	print(Board, N);
	Try(1);
	print(best, N);

	cout << endl << "Chi phi toi uu: " << Min << endl;
}
