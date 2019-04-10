#include<iostream>
#include<string>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int v) {
		val = v;
		next = nullptr;
	}
};

void print_linked_list(Node* n) {
	while (n != nullptr) {
		cout << n->val << ((n->next != nullptr) ? " -> " : "");
		n = n->next;
	}
	cout << endl;
}

Node* get_linked_list(int i) {
	Node* first = new Node(i % 10);
	Node* prev = first;
	i /= 10;

	while (i > 0) {
		Node* curr = new Node(i % 10);
		prev->next = curr;
		prev = curr;
		i /= 10;
	}

	return first; 
}

Node* add_lists(Node* a, Node* b, int carry) {
	// Base case
	if (a == nullptr && b == nullptr && carry == 0) return nullptr;
	// Compute sum from nodes and carry
	int sum = (a != nullptr ? a->val : 0) + (b != nullptr ? b->val : 0) + carry;
	// Next node (if any)
	Node* next_a = (a != nullptr ? a->next : nullptr);
	Node* next_b = (b != nullptr ? b->next : nullptr);

	// Create new node and recursively compute the remainder
	Node* c = new Node(sum % 10);
	c->next = add_lists(next_a, next_b, sum / 10);
	return c;
}

int main() {
	Node* a = get_linked_list(649);
	Node* b = get_linked_list(90003);
	print_linked_list(a);
	print_linked_list(b);
	Node* c = add_lists(a, b, 0);
	print_linked_list(c);
}
