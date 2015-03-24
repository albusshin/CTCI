#include <iostream>
#include <unordered_set>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d) :data(d), next(nullptr){};
};

Node *circleHead(Node *head) {
	Node *p = head;
	unordered_set<Node *> usp;
	while (p) {
		if (usp.find(p) == usp.end()) usp.insert(p);
		else return p;
		p = p->next;
	}
	return nullptr;
}

void test(Node *head) {
	cout << circleHead(head)->data;
}

int main() {
	Node *head = new Node(0), *p = head;
	for (int i = 1; i < 10; i++) {
		p->next = new Node(i);
		p = p->next;
	}
	p->next = head->next->next->next; //3
	test(head);
}