#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int i) {
		val = i;
		left = nullptr;
		right = nullptr;
	}
};

int minimum;
vector<int> min_path;

void printBT(const string& prefix, const Node* node, bool isLeft) {
    if (node != nullptr) {
        cout << prefix << (isLeft ? "├──" : "└──" ) << node->val << endl;
        printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void recurse(Node* curr, int sum, vector<int> path) {
	sum += curr->val;
	path.push_back(curr->val);

	if (curr->left == nullptr && curr->right == nullptr) {
		if (sum < minimum) {
			minimum = sum;
			min_path = path;
		}
		return;
	}

	if (curr->left != nullptr) recurse(curr->left, sum, path);
	if (curr->right != nullptr) recurse(curr->right, sum, path);
}

void get_minimum_path(Node* root) {
	minimum = INT_MAX;
	vector<int> temp;
	recurse(root, 0, temp);
}

int main() {
	Node* n10 = new Node(10);
	Node* n5_1 = new Node(5);
	Node* n5_2 = new Node(5);
	Node* n2 = new Node(2);
	Node* n1 = new Node(1);
	Node* n_1 = new Node(-1);

	n10->left = n5_1;
	n5_1->right = n2;
	n10->right = n5_2;
	n5_2->right = n1;
	n1->left = n_1;

	printBT("", n10, false);
	get_minimum_path(n10);
	cout << minimum << endl;

	for (int i : min_path) {
		cout << i << ",";
	}
	cout << endl;
}