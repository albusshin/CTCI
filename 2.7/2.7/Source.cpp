#include <iostream>
#include <stack>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d) :data(d), next(nullptr){};
};

int listLen(Node *head) {
	Node *p = head;
	int ret = 0;
	while (p) {
		ret++;
		p = p->next;
	}
	return ret;
}

bool isPalindrome(Node *head) {
	if (!head) return false;
	int len = listLen(head);
	Node *p = head;
	stack<int> stk;
	for (int i = 0; i < len/2; i++) {
		stk.push(p->data);
		p = p->next;
	}
	if (len % 2) p = p->next;
	for (; p; p = p->next) {
		if (stk.top() != p->data) return false;
		stk.pop();
	}
	return true;
}

void printList(Node *head) {
	Node *p = head;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void test(Node *head) {
	printList(head);
	cout << (isPalindrome(head) ? "Yes" : "No") << endl;
}

int main() {
	Node *head = new Node(0);
	head->next = new Node(1);
	head->next->next = new Node(4);
	head->next->next->next = new Node(1);
	head->next->next->next->next = new Node(0);
	test(head);
	head = new Node(1);
	head->next = new Node(1);
	head->next->next = new Node(4);
	head->next->next->next = new Node(1);
	head->next->next->next->next = new Node(0);
	test(head);
	head = new Node(1);
	head->next = new Node(0);
	head->next->next = new Node(0);
	head->next->next->next = new Node(1);
	test(head);
	head = new Node(0);
	head->next = new Node(0);
	head->next->next = new Node(0);
	head->next->next->next = new Node(1);
	test(head);
	head = nullptr;
	test(head);
}