#include<iostream>
#include<deque>
#include<climits>
#include<string>

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

int minimum_level(Node* root) {
	deque<Node*> Q;
	Q.push_back(root);

	int minimum_level_sum = INT_MAX;
	int min_level;
	int curr_level = 0;

	while(Q.size() > 0) {
		int level_sum = 0;
		curr_level++;

		int curr_size = Q.size();
		for (int i = 0; i < curr_size; i++) {
			level_sum += Q.front()->val;
			
			if (Q.front()->left != nullptr)
				Q.push_back(Q.front()->left);
			if (Q.front()->right != nullptr)
				Q.push_back(Q.front()->right);

			Q.pop_front();
		}
		
		if (level_sum < minimum_level_sum) {
			minimum_level_sum = level_sum;
			min_level = curr_level;
		}
	}

	return min_level;
}

int main() {
	Node* n3 = new Node(0);
	Node* n5 = new Node(5);
	Node* n1 = new Node(1);
	Node* n6 = new Node(6);
	Node* n2 = new Node(2);
	Node* n7 = new Node(1);
	Node* n4 = new Node(1);
	Node* n0 = new Node(0);
	Node* n8 = new Node(8);

	n3->left = n5;
	n3->right = n1;
	n5->left = n6;
	n5->right = n2;
	n2->left = n7;
	n2->right = n4;
	n1->left = n0;
	n1->right = n8;

	printBT("", n3, false);

	cout << "Level of tree with minimum level sum: " << minimum_level(n3) << endl;
}