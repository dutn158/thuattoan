/*
 * LietKeHoanVi.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: TranDu
 */
#include <iostream>
using namespace std;

int result[99];
int n = 3;

void print(int result[], int n) {
	for (int i = 0; i < n; i++) {
		cout << result[i];
	}
	cout << "\n";
}

void Try(int i, int n) {
	for (int k = 1; k <= n; k++) {
		result[i] = k;
		if (i < n) {
			Try(i + 1, n);
		} else {
			print(result, n);
			return;
		}
	}
}

int main(int argc, char **argv) {
	Try(0, n);
}




