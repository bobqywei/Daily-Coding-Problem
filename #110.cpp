#include<iostream>
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

void dfs(Node* curr, vector<int> curr_path, vector<vector<int>> &paths) {
	curr_path.push_back(curr->val);
	if (curr->left == nullptr && curr->right == nullptr) {
		paths.push_back(curr_path);
	} else if (curr->left == nullptr) {
		dfs(curr->right, curr_path, paths);
	} else if (curr->right == nullptr) {
		dfs(curr->left, curr_path, paths);
	} else {
		dfs(curr->left, curr_path, paths);
		dfs(curr->right, curr_path, paths);
	}
}

vector<vector<int>> getAllPaths(Node* root) {
	vector<vector<int>> paths;
	vector<int> curr_path;
	dfs(root, curr_path, paths);
	return paths;
}

int main() {
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);

	n1->left = n2;
	n1->right = n3;
	n3->right = n5;
	n3->left = n4;

	vector<vector<int>> paths = getAllPaths(n1);

	cout << "[";
	for (vector<int> path : paths) {
		cout << "[";
		for (int i : path) {
			cout << i << ","; 
		}
		cout << "], ";
	}
	cout << "]" << endl;
}