#include<iostream>
#include<vector>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node* parent;

	Node(int n) {
		val = n;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};

void printBT(const string& prefix, const Node* node, bool isLeft) {
    if (node != nullptr) {
        cout << prefix << (isLeft ? "├──" : "└──" ) << node->val << endl;
        printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void insert(Node* root, int i) {
	if (i < root->val) {
		if (root->left == nullptr) {
			Node* temp = new Node(i);
			temp->parent = root;
			root->left = temp;
		} else {
			insert(root->left, i);
		}

	} else {
		if (root->right == nullptr) {
			Node* temp = new Node(i);
			temp->parent = root;
			root->right = temp;
		} else {
			insert(root->right, i);
		}
	}
}

Node* createBST(vector<int>& v) {
	Node* root = new Node(v[0]);
	for (int i = 1; i < v.size(); i++) {
		insert(root, v[i]);
	}
	return root;
}

Node* find_node_in_BST(Node* curr, int i) {
	if (curr == nullptr) return nullptr;
	if (curr->val == i) return curr;
	else if (curr->val > i) return find_node_in_BST(curr->left, i);
	else return find_node_in_BST(curr->right, i);
}

Node* find_smallest_from_root(Node* root) {
	if (root == nullptr) return nullptr;
	else if (root->left == nullptr) return root;
	else return find_smallest_from_root(root->left); 
}

Node* inorder_successor(Node* n) {
	if (n == nullptr) return nullptr;
	
	Node* right = find_smallest_from_root(n->right);
	
	if (n->parent == nullptr) 
		return right;

	else if (n->parent->val <= n->val) // parent is smaller than curr
		return right;

	else if (right == nullptr) // nothing to right of curr
		return n->parent;

	else if (n->parent->val < right->val) // parent is next successor
		return n->parent;

	return right; // else, successor is in the right branch
}

int main() {
	vector<int> v({10, 5, 30, 22, 35});
	Node* root = createBST(v);
	printBT("", root, false);
	Node* toFind = find_node_in_BST(root, 22);
	Node* result = inorder_successor(toFind);

	if (result == nullptr)
		cout << "No Successor" << endl;
	else
		cout << "Inorder Successor of " << toFind->val << ": " << result->val << endl;
}
