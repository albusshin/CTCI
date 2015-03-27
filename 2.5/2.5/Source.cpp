#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d) :data(d), next(nullptr){};
};

/* With reverse order */
int addReverse(Node *head1, Node *head2) {
	int sum = 0;
	Node *p1 = head1, *p2 = head2;
	int pos;
	for (pos = 0; p1 && p2; pos++) {
		sum += (p1->data + p2->data) * pow(10, pos);
		p1 = p1->next;
		p2 = p2->next;
	}
	/* Case when number of digits not equal */
	if (p1) {
		for (; p1; pos++) {
			sum += (p1->data) * pow(10, pos);
			p1 = p1->next;
		}
	}
	if (p2) {
		for (; p2; pos++) {
			sum += (p2->data) * pow(10, pos);
			p2 = p2->next;
		}
	}
	return sum;
}

int listLen(Node *head) {
	Node *p = head;
	int ret = 0;
	while (p){
		ret++;
		p = p->next;
	}
	return ret;
}

/* With normal order */
int add(Node *head1, Node *head2) {
	int sum = 0;
	int len1 = listLen(head1), len2 = listLen(head2);
	for (Node *p = head1; p; p = p->next) {
		sum += p->data * pow(10, --len1);
	}
	for (Node *p = head2; p; p = p->next) {
		sum += p->data * pow(10, --len2);
	}
	return sum;
}

/* With normal order, another solution */
int add2(Node *head1, Node *head2) {
	Node *p1 = head1, *p2 = head2;
	int sum1 = 0, sum2 = 0;
	for (; p1; p1 = p1->next) {
		sum1 *= 10;
		sum1 += p1->data;
	}
	for (; p2; p2 = p2->next) {
		sum2 *= 10;
		sum2 += p2->data;
	}
	return sum1 + sum2;
}

void printList(Node *head) {
	Node *p = head;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void test(Node *head1, Node *head2) {
	printList(head1);
	printList(head2);
	cout << addReverse(head1, head2) << endl;
	cout << add(head1, head2) << endl;
	cout << add2(head1, head2) << endl;
}

int main() {
	Node *head1 = new Node(7);
	head1->next = new Node(1);
	head1->next->next = new Node(6);
	head1->next->next->next = new Node(1);
	Node *head2 = new Node(5);
	head2->next = new Node(9);
	head2->next->next = new Node(2);
	test(head1, head2);
}