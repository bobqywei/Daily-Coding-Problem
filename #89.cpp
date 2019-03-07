#include <iostream>
#include <limits.h>

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

bool isValidBST(Node* root, int max, int min) {
	if (root->val > max || root->val < min) {
		cout << max << ", " << min << ", " << root->val << ", " << endl; 
		return false;
	}

	if (root->right == nullptr && root->left == nullptr) {
		return true;
	} else if (root->right == nullptr) {
		return (root->left->val > root->val) ? false : isValidBST(root->left, root->val, min);
	} else if (root->left == nullptr) {
		return (root->right->val < root->val) ? false : isValidBST(root->right, max, root->val);
	} else {
		if (root->right->val < root->val || root->left->val > root->val) 
			return false;	
		else
			return (isValidBST(root->left, root->val, min) & isValidBST(root->right, max, root->val));	
	}
}

int main() {
	Node* n8 = new Node(8);
	Node* n3 = new Node(3);
	Node* n1 = new Node(1);
	Node* n6 = new Node(6);
	Node* n4 = new Node(4);
	Node* n7 = new Node(7);
	Node* n10 = new Node(10);
	Node* n14 = new Node(14);
	Node* n13 = new Node(13);

	n6->left = n4;
	n6->right = n7;
	n3->left = n1;
	n3->right = n6;
	n8->left = n3;
	n8->right = n10;
	n10->right = n14;
	n14->left = n13;

	cout << ((isValidBST(n8, INT_MAX, INT_MIN)) ? "Valid" : "Invalid") << endl;
}
