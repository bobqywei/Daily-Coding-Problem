#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<char, char> opposite({
	{'N', 'S'}, 
	{'S', 'N'}, 
	{'W', 'E'}, 
	{'E', 'W'}
});

class Node {
	unordered_set<char> S;
	unordered_set<char> N;
	unordered_set<char> E;
	unordered_set<char> W;

public:
	char name;

	Node(char c) {
		name = c;
	}
	
	bool has(char node, char dir) {
		if (dir == 'N') {
			return N.find(node) != N.end();
		} else if (dir == 'S') {
			return S.find(node) != S.end();
		} else if (dir == 'E') {
			return E.find(node) != E.end();
		} else if (dir == 'W') {
			return W.find(node) != W.end();
		}
	}

	void add(char node, char dir) {
		if (dir == 'N') {
			if (!has(node, dir)) N.insert(node);
		} else if (dir == 'S') {
			if (!has(node, dir)) S.insert(node);
		} else if (dir == 'E') {
			if (!has(node, dir)) E.insert(node);
		} else if (dir == 'W') {
			if (!has(node, dir)) W.insert(node);
		}
	}

	unordered_set<char> *get(char dir) {
		if (dir == 'N') {
			return &N;
		} else if (dir == 'S') {
			return &S;
		} else if (dir == 'E') {
			return &E;
		} else if (dir == 'W') {
			return &W;
		}
	}
};

bool fillMap(Node* nodeA, Node* nodeB, char dir) {
	cout << nodeA->name << ", " << dir << ", " << nodeB->name << endl;
	unordered_set<char> temp = *(nodeB->get(opposite[dir]));
	temp.insert(nodeB->name);

	for (char node : temp) {
		if (nodeA->has(node, dir)) return false;
		nodeA->add(node, opposite[dir]);
	}

	return true;
}

bool rulesAreValid(vector<string> &rules) {
	unordered_map<char, Node*> nodes;

	for (string rule : rules) {
		// parsing -----------------
		string token;
		istringstream ss(rule);
		ss >> token;
		char a = token[0];
		ss >> token;
		string dir = token;
		ss >> token;
		char b = token[0];
		// -------------------------

		if (nodes.find(a) == nodes.end()) nodes[a] = new Node(a);
		if (nodes.find(b) == nodes.end()) nodes[b] = new Node(b);

		if (dir.length() == 1) {
			if (!fillMap(nodes[a], nodes[b], dir[0])) return false;
			if (!fillMap(nodes[b], nodes[a], opposite[dir[0]])) return false;
		} else if (dir.length() == 2) {
			if (!fillMap(nodes[a], nodes[b], dir[0])) return false;
			if (!fillMap(nodes[b], nodes[a], opposite[dir[0]])) return false;
			if (!fillMap(nodes[a], nodes[b], dir[1])) return false;
			if (!fillMap(nodes[b], nodes[a], opposite[dir[1]])) return false;
		}
	}

	return true;
}

int main() {
	vector<string> rules({"A NW B", "A N B"});

	if (rulesAreValid(rules)) {
		cout << "Rules are valid." << endl;
	} else {
		cout << "INVALID." << endl;
	}
}