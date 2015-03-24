#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void compressStr(char *str) {
	int len = strlen(str);
	if (len == 0) return;
	char prev = str[0], now = prev;
	int count = 1;
	int i = 1;
	stringstream ss;
	while ((now = str[i++]) != NULL) {
		if (now == prev) count++;
		else {
			ss << prev << count;
			count = 1;
		}
		prev = now;
	}
	ss << prev << count;
	/* Find the length of stringstream */
	ss.seekp(0, ios::end);
	stringstream::pos_type newLen = ss.tellp();
	if (len <= newLen) return;
	else ss >> str;
}

void test(char *str) {
	cout << str << " ";
	compressStr(str);
	cout << str << endl;
}

int main() {
	char* str1 = new char[100];
	strcpy(str1, "aabcccccaaa");
	test(str1);
	strcpy(str1, "abcdefg");
	test(str1);
	strcpy(str1, "abbbccdd");
	test(str1);
}