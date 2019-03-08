#include <iostream>
#include <stdlib.h>
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

pair<bool, int> largest_BST(Node* root, int rmax, int rmin) {
	if (root == nullptr) return make_pair(true, 0);
	
	bool is_valid = (root->left == nullptr || root->left->val <= root->val) 
		& (root->right == nullptr || root->right->val >= root->val)
		& (root->val <= rmax & root->val >= rmin);
 	
	pair<bool, int> result_left = largest_BST(root->left, root->val, rmin);
	pair<bool, int> result_right = largest_BST(root->right, rmax, root->val);

	if (result_right.first && result_left.first && is_valid)
		return make_pair(true, result_left.second + result_right.second + 1);
	else
		return make_pair(false, max(result_left.second, result_right.second));
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

	pair<bool, int> largest = largest_BST(n8, INT_MAX, INT_MIN);
	cout << "The size of the largest BST is " << largest.second << endl;
}