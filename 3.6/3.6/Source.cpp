#include <iostream>
#include <stack>
using namespace std;

/* returns the count */
template <typename T>
int pour(stack<T>& stk1, stack<T>& stk2) {
	int sum = 0;
	while (!stk1.empty()) {
		stk2.push(stk1.top());
		stk1.pop();
		sum++;
	}
	return sum;
}

template <typename T>
T minPour(stack<T>& stk1, stack<T>& stk2, int size) {
	T ret = stk1.top();
	while (size--) {
		ret = min(stk1.top(), ret);
		stk2.push(stk1.top());
		stk1.pop();
	}
	stk1.push(ret);
	bool removed = false;
	while (!stk2.empty()) {
		if (stk2.top() == ret && !removed) {
			stk2.pop();
			removed = true;
		}
		if (stk2.empty()) break;
		stk1.push(stk2.top());
		stk2.pop();
	}
	return ret;
}

template <typename T>
void sortStack(stack<T>& stk) {
	stack<T> buffer;
	int len = pour(stk, buffer);
	pour(buffer, stk);
	while (len) minPour(stk, buffer, len--);
}

template <typename T>
void printStack(stack<T>& stk){
	stack<T> stk2(stk);
	while (!stk2.empty()) {
		cout << stk2.top() << " ";
		stk2.pop();
	}
	cout << endl;
}

template <typename T>
void test(stack<T>& stk) {
	printStack(stk);
	sortStack(stk);
	printStack(stk);
	cout << endl;
}

int main() {
	stack<int> stk;
	stk.push(1);
	stk.push(3);
	stk.push(6);
	stk.push(2);
	stk.push(4);
	stk.push(8);
	stk.push(9);
	test(stk);
	for (int i = 10; i >= 1; i--) stk.push(i);
	test(stk);
}