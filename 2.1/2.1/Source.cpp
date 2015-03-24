#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d) :data(d), next(nullptr){};
};

Node *removeDuplicate(Node *head) {
	Node *p = head;
	while (p) {
		Node *p2 = p->next, *prev = p;

		while (p2) {
			if (p->data == p2->data) {
				prev->next = p2->next;
				delete p2;
			}
			else prev = p2;
			p2 = prev->next;
		}
		p = p->next;
	}
	return head;
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
	cout << endl;
	head = removeDuplicate(head);
	printList(head);
}

int main() {
	Node* p = new Node(1), *head = p;
	p->next = new Node(0);
	p = p->next;
	p->next = new Node(1);
	p = p->next;
	p->next = new Node(1);
	p = p->next;
	p->next = new Node(1);
	p = p->next;
	p->next = new Node(1);
	p = p->next;
	p->next = new Node(1);
	p = p->next;
	p->next = new Node(2);
	p = p->next;
	p->next = new Node(2);
	p = p->next;
	p->next = new Node(3);
	p = p->next;
	p->next = new Node(2);
	p = p->next;
	p->next = new Node(4);
	p = p->next;
	test(head);
	head = new Node(0);
	test(head);
	head = nullptr;
	test(head);
}