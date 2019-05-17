#include<iostream>
#include<string>
#include<unordered_set>
#include<cstdlib>

using namespace std;

pair<int, string> recurse(string s, unordered_set<char>& ops) {
	char last = s[s.length()-1];
	string remaining = s.substr(0, s.length()-1);

	if (ops.find(last) != ops.end()) {
		pair<int, string> p1 = recurse(remaining, ops);
		pair<int, string> p2 = recurse(p1.second, ops);

		if (last == '+') {
			return make_pair(p2.first + p1.first, p2.second);
		} else if (last == '-') {
			return make_pair(p2.first - p1.first, p2.second);
		} else if (last == '/') {
			return make_pair(p2.first / p1.first, p2.second);
		} else if (last == '*') {
			return make_pair(p2.first * p1.first, p2.second);
		}

	}
	
	return make_pair((int)last - 48, remaining);
}

int compute(string s) {
	unordered_set<char> ops({'-', '+', '*', '/'});
	pair<int, string> result = recurse(s, ops);
	return result.first;
}

int main() {
	string s = "5711+-/3*211++-";
	cout << compute(s) << endl;
}