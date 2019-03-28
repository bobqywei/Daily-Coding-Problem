#include<iostream>
#include<unordered_set>
#include<deque>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node* parent;
	Node(Node* p, int v, bool is_left) {
		parent = p;
		val = v;
		left = nullptr;
		right = nullptr;

		if (p != nullptr) {
			if (is_left) p->left = this;
			else p->right = this;
		}
	}
};

Node* lowest_common_ancestor(Node* a, Node* b) {
	unordered_set<Node*> seen;
	while (b != nullptr) {
		if (b == a) return a;
		seen.insert(b);
		b = b->parent;
	}

	while(a != nullptr) {
		if (seen.find(a) != seen.end()) return a;
		a = a->parent;
	}

	return nullptr;
}



void printBT(const std::string& prefix, const Node* node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix << (isLeft ? "├──" : "└──" ) << node->val << std::endl;
        printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

int main() {
	Node* n3 = new Node(nullptr, 3, true);
	Node* n5 = new Node(n3, 5, true);
	Node* n1 = new Node(n3, 1, false);
	Node* n6 = new Node(n5, 6, true);
	Node* n2 = new Node(n5, 2, false);
	Node* n7 = new Node(n2, 7, true);
	Node* n4 = new Node(n2, 4, false);
	Node* n0 = new Node(n1, 0, true);
	Node* n8 = new Node(n1, 8, false);

	printBT("", n3, false);

	Node* a = n1;
	Node* b = n7;
	Node* LCA = lowest_common_ancestor(a, b);
	cout << "LCA of " << a->val << " and " << b->val << " is: " << LCA->val << endl;
}
