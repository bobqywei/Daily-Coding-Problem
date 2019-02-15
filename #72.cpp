#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

struct Node {
	char val;
	bool visited;
	vector<int> *adj;
	
	Node(char val) {
		val = val;
		visited = false;
		adj = new vector<int>;
	}
};

int maxFreq(string s) {
	unordered_map<char, int> freqs;
	int maxF = 0;
	for (char c : s) {
		if (freqs.find(c) == freqs.end()) freqs[c] = 1;
		else freqs[c]++;
		maxF = max(maxF, freqs[c]);
	}
	return maxF;
}

int dfs(int curr, vector<Node *> &nodes, string path) {
	if (nodes[curr]->visited) return INT_MAX;
	nodes[curr]->visited = true;

	path += nodes[curr]->val;
	if (nodes[curr]->adj->size() == 0) {
		nodes[curr]->visited = false;
		return maxFreq(path);
	}
	
	int most_frequent = 0;
	for (int node : *(nodes[curr]->adj)) {
		most_frequent = max(dfs(node, nodes, path), most_frequent);
		if (most_frequent == INT_MAX) return most_frequent;
	}
	nodes[curr]->visited = false;
	return most_frequent;
}

int largestValuePath(vector<pair<int, int>> &g, string s) {
	vector<Node *> nodes;
	for (char c : s) {
		nodes.push_back(new Node(c));
	}
	for (pair<int, int> p : g) {
		nodes[p.first]->adj->push_back(p.second);
	}

	string path;
	int most_frequent = 0;
	for (int i = 0; i < s.size(); i++) {
		most_frequent = max(most_frequent, dfs(i, nodes, path));
		if (most_frequent == INT_MAX) return -1;
	}
	return most_frequent;
}

int main() {
	string inp;
	string chars;
	cin >> chars;
	int edges;
	cin >> inp;
	edges = stoi(inp);
	vector<pair<int, int>> v;
	for (int i = 0; i < edges; i++) {
		cin >> inp;
		int a = stoi(inp);
		cin >> inp;
		int b = stoi(inp);
		v.push_back(make_pair(a, b));
	}
	cout << "Largest value path in the graph: " << largestValuePath(v, chars) << endl;
}
