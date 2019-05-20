#include<iostream>
#include<string>
#include<vector>

using namespace std;

void print_result(vector<pair<int, int>>& v) {
	cout << "[ ";
	for (pair<int, int> p : v) {
		cout << "(" << p.first << ", " << p.second << ") ";
	}
	cout << "]" << endl;
}

bool is_palindrome(string s) {
	for (int i = 0; i < s.length()/2; i++) {
		if (s[i] != s[s.length()-1-i]) return false;
	}
	return true;
}

vector<pair<int, int>> find_concat_palindromes(vector<string>& v) {
	vector<pair<int, int>> result;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (j != i) {
				string s = v[i] + v[j];
				if (is_palindrome(s)) {
					result.push_back(make_pair(i, j));
				} 
			}
		}
	}

	return result;
}

int main() {
	vector<string> v = {"code", "edoc", "da", "d"};
	vector<pair<int, int>> result = find_concat_palindromes(v);
	print_result(result);
}