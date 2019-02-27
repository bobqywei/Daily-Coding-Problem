#include <iostream>

using namespace std;

struct Node {
	char val;
	Node* left;
	Node* right;

	Node(char c) {
		val = c;
		left = nullptr;
		right = nullptr;
	}
};

void printTree(Node* root) {
	if (root == nullptr) return;
	printTree(root->left);
	cout << root->val << endl;
	printTree(root->right);
}

void reverseTree(Node* root) {
	if (root == nullptr) return;
	reverseTree(root->left);
	reverseTree(root->right);
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

int main() {
	Node* a = new Node('a');
	Node* b = new Node('b');
	Node* c = new Node('c');
	Node* d = new Node('d');
	Node* e = new Node('e');
	Node* f = new Node('f');

	a->left = b;
	b->left = d;
	b->right = e;
	a->right = c;
	c->left = f;

	printTree(a);
	cout << endl;
	reverseTree(a);
	printTree(a);
	cout << endl;
}