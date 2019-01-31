#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> *splitSentence(int k, vector<string> &tokens) {
	vector<string> *sentences = new vector<string>;
	string curr = "";
	int numTokens = 0;
	for (string token : tokens) {
		if (curr.length() + token.length() + numTokens > k) {
			sentences->push_back(curr);
			curr = token;
			numTokens = 1;
		} else {
			if (numTokens > 0) curr += " ";
			curr += token;
			numTokens++;
		}
	}
	sentences->push_back(curr);

	return sentences;
}

int main() {
	string inp;
	cin >> inp;
	int k = stoi(inp);

	while (getline(cin, inp)) {
		stringstream ss(inp);
		vector<string> v;
		string token;

		while (ss >> token) {
			v.push_back(token);
		}

		vector<string>* sentences = splitSentence(k, v);

		for (string s : *sentences) {
			cout << s << endl;
		}
	}
}