#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node {
	char c;
	unordered_map<char, Node*> children;

public:
	Node(char i) {
		c = i;
	}

	char getChar() {
		return c;
	} 

	bool contains(char c) {
		return children.find(c) != children.end();
	}

	Node* getNodeForChar(char c) {
		return children[c];
	}

	void addNodeForChar(char c, Node* n) {
		children[c] = n;
	}

	vector<string>* getStringsWithPrefix(string prefix) {
		vector<string>* ret = new vector<string>;
		for (pair<char, Node*> p : children) {
			if (p.first == '*') {
				ret->push_back(prefix);
			} else {
				vector<string>* v = p.second->getStringsWithPrefix(prefix + p.first);
				ret->insert(ret->end(), v->begin(), v->end());
				free(v);
			}
		}
		return ret;
	}
};

class Trie {
	unordered_map<char, Node*> roots;

public:
	Trie(vector<string> &v) {
		for (string s : v) {
			Node* curr;

			if (roots.find(s[0]) == roots.end()) {
				curr = new Node(s[0]);
				roots[s[0]] = curr;
			} else {
				curr = roots[s[0]];
			}

			if (s.length() > 1) {
				for (char c : s.substr(1, s.length()-1)) {
					if (curr->contains(c)) {
						curr = curr->getNodeForChar(c);
					} else {
						Node* temp = new Node(c);
						curr->addNodeForChar(c, temp);
						curr = temp;
					}
				}
			}

			curr->addNodeForChar('*', new Node('*'));
		}
	}

	vector<string>* queryString(string s) {
		if (roots.find(s[0]) == roots.end()) return new vector<string>;

		Node* curr = roots[s[0]];

		for (int i = 1; i < s.length(); i++) {
			if (!curr->contains(s[i])) return new vector<string>;
			curr = curr->getNodeForChar(s[i]);
		}

		return curr->getStringsWithPrefix(s);
	}
};



int main() {
	string in;
	getline(cin, in);
	istringstream ss(in);

	string token;
	vector<string> words;

	while (getline(ss, token, ',')) {
		words.push_back(token);
	}

	Trie* dict = new Trie(words);

	while (cin >> in) {
		vector<string>* matchingWords = dict->queryString(in);
		if (matchingWords->size() > 0) {
			cout << "Matches: ";
			for (string s : *matchingWords) {
				cout << s << ", ";
			}
		} else {
			cout << "No matches were found.";
		}
		cout << endl;
	}
}
