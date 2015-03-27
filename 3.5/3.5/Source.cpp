#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class MyQueue{
	stack<T> stk1;
	stack<T> stk2;

	void pour(stack<T>& stk1, stack<T>& stk2) {
		while (!stk1.empty()) {
			stk2.push(stk1.top());
			stk1.pop();
		}
	}

public:
	void enqueue(T val) {
		stk1.push(val);
	}

	T dequeue() {
		pour(stk1, stk2);
		T ret = stk2.top();
		stk2.pop();
		pour(stk2, stk1);
		return ret;
	}

	bool empty() {
		return stk1.empty();
	}
};

template <typename T>
void test(MyQueue<T> q) {
	while (!q.empty()) {
		cout << q.dequeue() << " ";
	}
}

int main() {
	MyQueue<int> q;
	for (int i = 1; i <= 10; i++) {
		q.enqueue(i);
	}
	test(q);
}