#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d) :data(d), next(nullptr){};
};

void deleteNode(Node *node) {
	Node *first = node,
		*second = node->next;
	while (second->next) {
		first->data = second->data;
		first = first->next;
		second = second->next;
	}
	first->data = second->data;
	first->next = nullptr;
}

void printList(Node *head) {
	Node *p = head;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void test(Node *head, Node *node) {
	printList(head);
	deleteNode(node);
	printList(head);
}

int main() {
	Node *head = new Node(0), *p = head;
	for (int i = 1; i < 10; i++) {
		p->next = new Node(i);
		p = p->next;
	}
	test(head, head->next->next->next);
}