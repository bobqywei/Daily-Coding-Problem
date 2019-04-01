#include<iostream>
#include<string>
#include<vector>

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

void printBT(const string& prefix, const Node* node, bool isLeft) {
    if (node != nullptr) {
        cout << prefix << (isLeft ? "├──" : "└──" ) << node->val << endl;
        printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

int find_tree_size(Node* root, int size, vector<Node*>& trees) {
	if (root == nullptr) return 0;
	int left_size = find_tree_size(root->left, size, trees);
	int right_size = find_tree_size(root->right, size, trees);
	int tree_size = left_size + right_size + 1;

	if (size == tree_size) trees.push_back(root);
	return tree_size;
}

bool are_identical(Node* a, Node* b) {
	if (a == nullptr && b == nullptr) 
		return true;
	else if (a != nullptr && b != nullptr) {
		if (a->val != b->val) return false;
		return are_identical(a->left, b->left) && are_identical(a->right, b->right);
	} 
	else 
		return false;
}

bool is_subtree(Node* t, Node* s) {
	vector<Node*> possibleTrees;
	int subtree_size = find_tree_size(s, -1, possibleTrees);

	find_tree_size(t, subtree_size, possibleTrees);

	for (Node* root : possibleTrees) {
		if (are_identical(s, root)) return true;
	}
	return false;
}

int main() {
	Node* n3 = new Node(3);
	Node* n5 = new Node(5);
	Node* n1 = new Node(1);
	Node* n6 = new Node(6);
	Node* n2 = new Node(2);
	Node* n7 = new Node(7);
	Node* n4 = new Node(4);
	Node* n0 = new Node(0);
	Node* n8 = new Node(8);

	n3->left = n5;
	n3->right = n1;
	n5->left = n6;
	n5->right = n2;
	n2->left = n7;
	n2->right = n4;
	n1->left = n0;
	n1->right = n8;

	Node* m5 = new Node(5);
	Node* m6 = new Node(6);
	Node* m2 = new Node(2);
	Node* m7 = new Node(7);
	Node* m1 = new Node(1);

	m5->left = m6;
	m5->right = m2;
	m2->left = m7;
	m2->right = m1;

	Node* t = n3;
	Node* s = m5;

	printBT("", t, false);
	printBT("", s, false);

	bool result = is_subtree(t, s);
	if (result) cout << "Yes, it is a subtree." << endl;
	else cout << "No, it is not." << endl;
}
