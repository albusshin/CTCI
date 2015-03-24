#include <iostream>
#include <vector>
using namespace std;

void setZero(int **arr, int m, int n) {
	vector<pair<int, int>> vp;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				vp.push_back(make_pair(i, j));
			}
		}
	}
	for (auto p : vp) {
		int f = p.first, s = p.second;
		for (int j = 0; j < n; j++) {
			arr[f][j] = 0;
		}
		for (int j = 0; j < m; j++) {
			arr[j][s] = 0;
		}
	}
}

void printBoard(int **arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) cout << arr[i][j];
		cout << endl;
	}
	cout << endl;
}

void test (int **arr, int m, int n) {
	printBoard(arr, m, n);
	setZero(arr, m, n);
	printBoard(arr, m, n);
}

int main() {
	int **arr = new int* [10];
	for (int i = 0; i < 10; i++) arr[i] = new int[10];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = i + 1;
		}
	}
	arr[1][2] = 0;
	arr[2][3] = 0;
	arr[6][8] = 0;
	test(arr, 9, 10);
}