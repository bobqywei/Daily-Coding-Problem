#include <vector>
#include <unordered_map>
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

	vector<int>* findNextToken(string s) {
		vector<int>* possibleTokens = new vector<int>;
		Node* curr = this;
		int length = 0;

		for (char c : s) {
			if (!curr->contains(c)) return possibleTokens;
			curr = curr->getNodeForChar(c);
			length++;
			if (curr->contains('*')) possibleTokens->push_back(length);
		}

		return possibleTokens;
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

	vector<string>* tokenizeString(string s) {
		vector<string>* tokens = new vector<string>;
		if (string.length() == 0) return tokens;
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

}
