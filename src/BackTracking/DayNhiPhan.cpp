/*
 * DayNhiPhan.cpp
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

void Try(int i) {
	for (int k = 0; k <= 1; k++) {
		result[i] = k;
		if (i < n) {
			Try(i + 1);
		} else {
			print(result, n);
			return;
		}
	}
}

int main(int argc, char **argv) {
	Try(0);
}

