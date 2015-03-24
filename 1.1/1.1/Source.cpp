#include <iostream>
#include <unordered_set>
using namespace std;

bool allDifferent(const char *str) {
	unordered_set<char> s;
	char *p = (char *)str;
	while (p && *p != NULL) {
		if (s.find(*p) != s.end()) return false;
		s.insert(*p);
		p++;
	}
	return true;
}

int allDifferentWithoutDS(const char *str) {
	for (char* p = (char *)str; *p != NULL; p++) {
		for (char *p2 = p + 1; *p2 != NULL; p2++) {
			if (*p == *p2) return false;
		}
	}
	return true;
}

void test(const char *str) {
	cout << str << " " << allDifferent(str) << endl;
	cout << str << " " << allDifferentWithoutDS(str) << endl;
}

int main() {
	test("abcdefg");
	test("aabcdefg");
	test("foobarr");
	test("fobar");
}