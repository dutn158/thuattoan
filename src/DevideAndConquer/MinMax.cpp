/*
 * MinMax.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: TranDu
 */

#include <iostream>

using namespace std;

void MinMax(int a[], int l, int r, int &min, int &max) {
	int min1, min2, max1, max2;
	if (l == r) {
		min = a[l];
		max = a[l];
	} else {
		MinMax(a, l, (l + r) / 2, min1, max1);
		MinMax(a, (l + r) / 2 + 1, r, min2, max2);
		if (min1 < min2) {
			min = min1;
		} else {
			min = min2;
		}
		if (max1 > max2) {
			max = max1;
		} else {
			max = max2;
		}
	}

}

int main(int argc, char **argv) {
	int a[] = {15, 64, 34, 52, 9, 26, 31, 4};
	int n = 7;
	int min = 0;
	int max = 0;

	MinMax(a, 0, n, min, max);

	cout << "Max = " << max << endl;
	cout << "Min = " << min << endl;

}


