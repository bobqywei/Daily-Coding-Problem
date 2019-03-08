#include<iostream>
#include<stdlib.h>
#include<limits.h>

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

void search_max(Node* curr, int path_sum, int* maximum) {
	if (curr == nullptr) return;
	int curr_path_sum = max(curr->val + path_sum, 0);
	*maximum = max(*maximum, curr_path_sum);
	search_max(curr->left, curr_path_sum, maximum);
	search_max(curr->right, curr_path_sum, maximum);
}

int max_path_sum(Node* root) {
	int maximum = INT_MIN;
	search_max(root, 0, &maximum);
	return maximum;
}

int main() {
	Node* n8 = new Node(8);
	Node* n3 = new Node(-3);
	Node* n1 = new Node(100);
	Node* n6 = new Node(6);
	Node* n4 = new Node(4);
	Node* n7 = new Node(7);
	Node* n10 = new Node(-10);
	Node* n14 = new Node(-14);
	Node* n13 = new Node(-13);

	n6->left = n4;
	n6->right = n7;
	n3->left = n1;
	n3->right = n6;
	n8->left = n3;
	n8->right = n10;
	n10->right = n14;
	n14->left = n13;

	cout << "The largest path sum is " << max_path_sum(n8) << endl;
}