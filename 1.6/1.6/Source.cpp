#include <iostream>
using namespace std;

void rotateClockwise90(char **arr, int n) {
	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {
			char tmp = arr[n-j-1][i];
			arr[n-j-1][i] = arr[n-i-1][n-j-1];
			arr[n-i-1][n-j-1] = arr[j][n-i-1];
			arr[j][n-i-1] = arr[i][j];
			arr[i][j] = tmp;
		}
	}
}

void printBoard(char **arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void test(char **arr, int n) {
	printBoard(arr, n);
	rotateClockwise90(arr, n);
	printBoard(arr, n);
}

int main() {
	char **arr = new char *[10];
	for (int i = 0; i < 10; i++) arr[i] = new char[10];
	strcpy(arr[0], "123456789");
	strcpy(arr[1], "234567890");
	strcpy(arr[2], "345678901");
	strcpy(arr[3], "456789012");
	strcpy(arr[4], "567890123");
	strcpy(arr[5], "678901234");
	strcpy(arr[6], "789012345");
	strcpy(arr[7], "890123456");
	strcpy(arr[8], "901234567");

	test((char **)arr, 9);
}