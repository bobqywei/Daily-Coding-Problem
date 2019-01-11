#include <iostream>
using namespace std;

class TreeNode {
public:
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) {
		value = val;
		left = nullptr;
		right = nullptr;
	}
};

// At each node must return whether tree under node is unival
// and the number of unival trees under
pair<bool, int> getUnivalTrees(TreeNode* t) {
	if (t->left == nullptr && t->right == nullptr) {
		return make_pair(true, 1);

	} else if (t->left == nullptr) {
		pair<bool, int> p = getUnivalTrees(t->right);

		// Check if current tree is unival
		if (p.first && t->value == t->right->value) return make_pair(true, p.second + 1);
		else return make_pair(false, p.second);

	} else if (t->right == nullptr) {
		pair<bool, int> p = getUnivalTrees(t->left);

		// Check if current tree is unival
		if (p.first && t->value == t->left->value) return make_pair(true, p.second + 1);
		else return make_pair(false, p.second);

	} else {
		pair<bool, int> left = getUnivalTrees(t->left);
		pair<bool, int> right = getUnivalTrees(t->right);

		if (left.first && right.first && t->value == t->right->value && t->value == t->left->value) {
			// Both branches and current tree are all unival
			return make_pair(true, left.second + right.second + 1);
		} else {
			// Sum number of unival subtrees from both branches
			return make_pair(false, left.second + right.second);
		}
	}
}

int main() {
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(0);
	root->right->left = new TreeNode(1);
	root->right->right = new TreeNode(0);
	root->right->left->left = new TreeNode(1);
	root->right->left->right = new TreeNode(1);

	cout << getUnivalTrees(root).second << endl;
}
