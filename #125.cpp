#include<iostream>
#include<unordered_map>
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

void dfs(Node* curr, unordered_map<int, vector<Node*>>& map) {
	if (curr == nullptr) return;
	
	if (map.find(curr->val) == map.end()) {
		vector<Node*> nodes{curr};
		map[curr->val] = nodes;
	} else {
		map[curr->val].push_back(curr);
	}

	dfs(curr->left, map);
	dfs(curr->right, map);
}

pair<Node*, Node*> find_pair(Node* root, int k) {
	unordered_map<int, vector<Node*>> node_map;
	dfs(root, node_map);

	for (pair<int, vector<Node*>> p : node_map) {
		int residual = k - p.first;
		if (residual == p.first) {
			if (p.second.size() > 1) return make_pair(p.second[0], p.second[1]);
		} else {
			if (node_map.find(residual) != node_map.end()) return make_pair(p.second[0], node_map[residual][0]);
		}
	}

	return make_pair(nullptr, nullptr);
}

int main() {
	Node* n10 = new Node(10);
	Node* n5 = new Node(5);
	Node* n15 = new Node(15);
	Node* n11 = new Node(11);
	Node* _n15 = new Node(15);

	n10->left = n5;
	n10->right = n15;
	n15->left = n11;
	n15->right = _n15;

	printBT("", n10, false);

	pair<Node*, Node*> result = find_pair(n10, 16);

	if (result.first == nullptr || result.second == nullptr)
		cout << "No such pair found" << endl;
	else
		cout << result.first->val << ", " << result.second->val << endl;
}