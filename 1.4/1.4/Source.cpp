#include <iostream>
using namespace std;

void replaceSpace(char* str) {
	int count = 0;
	for (char *p = str; *p != NULL; p++) {
		if (*p == ' ') count++;
	}
	int len = strlen(str);
	int newLen = len + count * 2;
	str[newLen] = NULL;
	char *p = str + len - 1;
	for (int i = newLen - 1; i >= 0; i--) {
		if (*p != ' ') str[i] = *p;
		else {
			str[i--] = '0';
			str[i--] = '2';
			str[i] = '%';
		}
		p--;
	}
}

void test(char *str) {
	cout << str << endl;
	replaceSpace(str);
	cout << str << endl;
}
int main() {
	char *str1 = new char[200];
	strcpy(str1, "There is a cat sitting in the chair!");
	test(str1);
}