#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d) :data(d), next(nullptr){};
};

Node *slice(Node *head, int x) {
	Node *first = new Node(0), *pfirst = first;
	Node *second = new Node(0), *psecond = second;
	Node *p = head;
	while (p) {
		Node *next = p->next;
		if (p->data < x) {
			pfirst->next = p;
			pfirst = pfirst->next;
			pfirst->next = nullptr;
		}
		else {
			psecond->next = p;
			psecond = psecond->next;
			psecond->next = nullptr;
		}
		p = next;
	}
	pfirst->next = second->next;
	Node *ret = first->next;
	delete first;
	delete second;
	return ret;
}

void printList(Node *head) {
	Node *p = head;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void test(Node *head, int x) {
	printList(head);
	head = slice(head, x);
	printList(head);
}

int main(){
	Node *head = new Node(10), *p = head;
	for (int i = 9; i >= 0; i--) {
		p->next = new Node(i);
		p = p->next;
	}
	test(head, 9);
}