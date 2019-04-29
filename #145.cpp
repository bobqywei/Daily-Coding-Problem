#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int v) {
		val = v;
		next = nullptr;
	}
};

void print(Node* head) {
	while (head != nullptr) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

Node* swap_every_two(Node* head) {
	Node* prev = nullptr;
	Node* a = head;
	Node* b = head->next;
	Node* new_head = (b == nullptr ? a : b);

	while (b != nullptr) {
		// set the node before the current pair
		if (prev != nullptr) prev->next = b;
		// swap the current pair
		Node* temp = b->next;
		b->next = a;
		a->next = temp;
		// set previous node and the next node pair
		prev = a;
		a = temp;
		b = (a == nullptr) ? nullptr : a->next;
	}

	return new_head;
}

int main() {
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	print(n1);
	Node* new_list = swap_every_two(n1);
	print(new_list);
}