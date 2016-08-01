/*
 * NguoiDuLich.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: TranDu
 */

#include <iostream>
using namespace std;

#define MAX 500

#define N 4

int Board[N + 1][N + 1];
int DaDi[N + 1];
int ChiPhi[N + 1];
int MinMoney = MAX;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Board[i][j] = MAX;
		}
		DaDi[i] = 0;
		ChiPhi[i] = 0;
	}
	DaDi[1] = 1;
	ChiPhi[1] = 0;
}

void print(int a[][N], int n) {
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
		if (DaDi[i] == 0) {
			DaDi[i] = k;



			DaDi[i] = 0;
		}
	}
}

int main(int argc, char **argv) {
	init();
	Try(2);
}
