#include <iostream>

using namespace std;

void quickSort(int a[], int l, int r) {
	int i = l;
	int j = r;

	int middle = (l + r) / 2;
	int pivot = a[middle];

	while (i <= j) {
		while (a[i] < pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (l < j) {
		quickSort(a, l, j);
	}
	if (r > i) {
		quickSort(a, i, r);
	}

}

void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

int main(int argc, char **argv) {
	int a[] = {13, 31, 21, 41, 34, 45, 61, 46, 71, 9};
	int n = 9;

	quickSort(a, 0, n);

	print(a, 9);

}




