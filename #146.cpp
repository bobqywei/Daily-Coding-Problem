#include<iostream>
#include<string>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int v) {
		val = v;
		left = nullptr;
		right = nullptr;
	}
};

void printBT(string prefix, Node* node, bool isLeft) {
    if (node != nullptr) {
        cout << prefix << (isLeft ? "├──" : "└──" ) << node->val << endl;
        printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

bool recurse(Node* curr) {
	// Base case: nullptr is a zero tree
	if (curr == nullptr) return true;
	
	// Check if left and right subtrees are zero or nullptr
	// If so, subtree can be pruned
	bool left_is_zero = recurse(curr->left);
	bool right_is_zero = recurse(curr->right);
	if (left_is_zero) curr->left = nullptr;
	if (right_is_zero) curr->right = nullptr;

	// If left and right subtrees are zero and curr is zero,
	// then the current subtree can be pruned.
	if (left_is_zero && right_is_zero && curr->val == 0) return true;
	else return false;
}

Node* prune_zeros(Node* root) {
	// recursively prune tree
	bool all_zero = recurse(root);
	// return nullptr if entire tree is zero
	if (all_zero)
		return nullptr;
	else
		return root;
}

int main() {
	Node* n1 = new Node(0);
	Node* n2 = new Node(1);
	Node* n3 = new Node(0);
	Node* n4 = new Node(1);
	Node* n5 = new Node(0);
	Node* n6 = new Node(0);
	Node* n7 = new Node(0);

	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;
	n4->left = n6;
	n4->right = n7;

	printBT("", n1, false);
	Node* pruned_tree = prune_zeros(n1);
	printBT("", pruned_tree, false);
}
