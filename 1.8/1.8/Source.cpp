#include <string>
using namespace std;

bool isRotated(string s1, string s2) {
	if (s1.length == s2.length && s1.length != 0) {
		return isSubstring(s1 + s1, s2);
	}
	if (s1.length == 0 && s2.length == 0) return true;
	return false;
}