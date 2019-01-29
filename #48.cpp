#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
	char val;
	Node* left;
	Node* right;

	Node(char c) {
		val = c;
		left = nullptr;
		right = nullptr;
	}
};

void printVector(vector<char> &v, int left, int right) {
	for (int i = left; i <= right; i++) {
		cout << v[i] << ",";
	}
	cout << endl;
}

Node* constructTree(vector<char> &inOrder, int leftIn, int rightIn, vector<char> &preOrder, int leftPre, int rightPre) {
	// assert(leftIn - rightIn == leftPre - rightPre);

	if (rightIn == leftIn) {
		// assert(inOrder[leftIn] == preOrder[leftPre]);
		return new Node(inOrder[leftIn]);
	}

	Node* root = new Node(preOrder[leftPre]);

	int rootIndex = leftIn;
	while (inOrder[rootIndex] != root->val) {
		rootIndex++;
	}

	int leftTreeSize = rootIndex - leftIn;
	int rightTreeSize = rightIn - rootIndex;

	root->left = constructTree(inOrder, leftIn, rootIndex-1, preOrder, leftPre+1, leftPre+leftTreeSize);
	root->right = constructTree(inOrder, rootIndex+1, rightIn, preOrder, leftPre+leftTreeSize+1, rightPre);

	return root;
}

void inOrderTraversal(Node* root) {
	if (root == nullptr) return;
	inOrderTraversal(root->left);
	cout << root->val << endl;
	inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
	if (root == nullptr) return;
	cout << root->val << endl;
	inOrderTraversal(root->left);
	inOrderTraversal(root->right);
}

int main() {
	string s = "abdecfg";
	string s2 = "dbeafcg";

	vector<char> v;
	vector<char> v2;

	for (char c : s) {
		v.push_back(c);
	}

	for (char c : s2) {
		v2.push_back(c);
	}

	Node* root = constructTree(v2, 0, v2.size()-1, v, 0, v.size()-1);
	inOrderTraversal(root);
	cout << endl;
	preOrderTraversal(root);
}
