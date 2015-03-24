#include <iostream>
using namespace std;

void swap(char* p1, char* p2) {
	char c;
	c = *p1;
	*p1 = *p2;
	*p2 = c;
}

void reverse(char* str) {
	int len = strlen(str);
	for (int i = 0; i < len/2; i++) {
		swap(str + i, str + (len - i - 1));
	}
}

void test(char* str) {
	cout << str << " ";
	reverse(str);
	cout << str << endl;
}

int main() {
	char *str1 = new char[10];
	strcpy(str1, "abcdefgh");
	test(str1);
}