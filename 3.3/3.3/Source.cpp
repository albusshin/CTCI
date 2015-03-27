#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int limit = 2;

template <typename T>
class SetOfStacks {
public:
	vector<stack<T>> stks;
	void push(T val) {
		if (stks.empty() || stks.back().size() == limit) stks.push_back(*new stack<T>());
		stks.back().push(val);
	}

	void pop() {
		if (stks.empty()) return;
		stks.back().pop();
		if (stks.back().empty()) stks.erase(stks.end() - 1);
	}

	T top() {
		if (stks.empty()) {
			stack<T> tmps;
			return tmps.top();
		}
		return stks.back().top();
	}

	void popAt(int index) {
		stks.at(index).pop();
	}

	bool empty() {
		return stks.empty();
	}
};

template <typename T>
void test(SetOfStacks<T> s) {
	s.popAt(0);
	while (!s.empty()) {
		cout << "top: " << s.top() << " size of stacks: " << s.stks.size() << endl;
		s.pop();
	}
}

int main() {
	SetOfStacks<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	test(s);
}