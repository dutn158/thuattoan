/*
 * MaDiTuan.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: TranDu
 */
#include <iostream>
using namespace std;

int a[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int b[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int result[8][8];

void printArray(int result[][8]) {
	cout<< "=================>" << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << result[i][j] << "\t";
		}
		cout << endl;
	}
	cout<< "<=================" << endl;

}

void Try(int i, int x, int y) {
	int u, v;
	for (int k = 0; k < 8; k++) {
		u = x + a[k];
		v = y + b[k];

		if (u >= 0 && u < 8 && v >= 0 && v < 8 && result[u][v] == 0) {
			result[u][v] = i;
			if (i < 8*8) {
				Try(i + 1, u, v);
			} else {
				printArray(result);
			}
			result[u][v] = 0;
		}
	}
}

void initData(int result[][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			result[i][j] = 0;
		}
	}
}

int main(int argc, char **argv) {
	initData(result);
	printArray(result);
	result[0][0] = 1;
	Try(2, 0, 0);

}

