#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class MinStack {
	stack<T> stk;
	stack<T> minStack;
public:
	void push(T val) {
		if (stk.empty() || val < stk.top()) minStack.push(val);
		stk.push(val);
	}

	void pop() {
		if (stk.top() == minStack.top()) minStack.pop();
		stk.pop();
	}

	T top() {
		return stk.top();
	}

	T min() {
		return minStack.top();
	}

	bool empty() {
		return stk.empty();
	}
};

template<typename T>
void test(MinStack<T>& minStack) {
	while (!minStack.empty()) {
		cout << "top: " << minStack.top()  << " min: " << minStack.min() << endl;
		minStack.pop();
	}
}

int main() {
	MinStack<int> minStack;
	minStack.push(10);
	minStack.push(9);
	minStack.push(11);
	minStack.push(8);
	minStack.push(100);
	minStack.push(1);
	test(minStack);
}