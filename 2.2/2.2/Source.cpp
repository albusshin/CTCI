#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d) :data(d), next(nullptr){};
};

Node *reverseK(Node *head, int k) {
	Node *p = head;
	int len = 0;
	while (p) {
		p = p->next;
		len++;
	}
	int i = 0;
	for (p = head; p && i < len - k; p = p->next, i++);
	return p;
}

void test(Node *head, int k) {
	cout << reverseK(head, k)->data << endl;
}

int main() {
	Node *head = new Node(0), *p = head;
	for (int i = 1; i <= 9; i++) {
		p->next = new Node(i);
		p = p->next;
	}
	test(head, 5);
}