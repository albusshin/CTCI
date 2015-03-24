#include <iostream>
#include <unordered_map>
using namespace std;

bool isChangable(const char *str1, const char *str2) {
	unordered_map<char, int> umci;
	for (char *p = (char *)str1; *p != NULL; p++) {
		if (umci.find(*p) == umci.end()) umci[*p] = 1;
		else umci[*p]++;
	}
	for (char *p = (char *)str2; *p != NULL; p++) {
		if (umci.find(*p) == umci.end()) return false;
		else umci[*p]--;
	}
	for (auto pair : umci) {
		if (pair.second != 0) return false;
	}
	return true;
}

void test(const char *str1, char *str2){
	cout << str1 << " " << str2 << " " << isChangable(str1, str2) << endl;
}

int main() {
	test("abcdefg", "bcdefag");
	test("abccc", "bcdab");
	test("foobar", "barfoo");
}