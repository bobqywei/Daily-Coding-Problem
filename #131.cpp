#include<iostream>
#include<unordered_map>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node* rand;
	Node(int i) {
		val = i;
		next = nullptr;
		rand = nullptr;
	}
};

void print_list(Node* root) {
	while(root != nullptr) {
		cout << root->val << "[";
		if (root->rand != nullptr) cout << root->rand->val;
		cout << "] ->";
		root = root->next;
	}
	cout << endl;
}

Node* recurse(Node* root, unordered_map<Node*, Node*>& addr_map) {
	if (root == nullptr) return nullptr;
	// return existing copy if previously created
	if (addr_map.find(root) != addr_map.end()) return addr_map[root];

	addr_map[root] = new Node(root->val);
	// evaluate next and random pointers
	addr_map[root]->next = recurse(root->next, addr_map);
	addr_map[root]->rand = recurse(root->rand, addr_map);
	return addr_map[root];
}

Node* deep_copy(Node* root) {
	unordered_map<Node*, Node*> addr_map;
	return recurse(root, addr_map);
}

int main() {
	Node* n0 = new Node(0);
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);

	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	n0->rand = n3;
	n4->rand = n0;
	n1->rand = n2;

	print_list(n0);
	Node* new_root = deep_copy(n0);

	n0->val = 4;
	n1->val = 3;
	n2->val = 99;
	n3->val = 1;
	n4->val = 0;

	print_list(n0);
	print_list(new_root);
}
