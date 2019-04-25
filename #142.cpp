#include<deque>
#include<iostream>
#include<string>

using namespace std;

bool is_balanced(const string s) {
	deque<char> stack;
	int num_star = 0;
	for (char c : s) {
		if (c == '*') {
			// Count number of stars
			num_star++;

		} else if (c == '(') {
			stack.push_back(c);

		} else if (c == ')') {
			if (stack.empty()) {
				// If no '(' or star available, then string is not balanced 
				if (--num_star < 0) return false;
			} else {
				stack.pop_back();
			}
		}
	}

	// Normal balanced parens check:
	// If no extra "(", then string is balanced
	if (stack.size() == 0) 
		return true;
	// More extra parentheses than available stars
	// String cannot be balanced
	else if (num_star < stack.size())
		return false;

	int extra_parens = stack.size();
	
	int i = 0;
	int j = 0;
	// Find the left most parens as these are the
	// ones to be left over
	int *leftmost_parens = new int[extra_parens];
	while (i < extra_parens && j < s.length()) {
		if (s[j] == '(') leftmost_parens[i++] = j;
		j++; 
	}

	i = 0;
	j = s.length() - 1;
	// Find the right most stars as these are the most useful
	// right-most stars can balance more chracters
	int *rightmost_stars = new int[extra_parens];
	while (i < extra_parens && j >= 0) {
		if (s[j] == '*') rightmost_stars[i++] = j;
		j++;
	}

	// Make sure that all extra "(" can be matched with
	// a particular star to its left
	for (int i = 0; i < extra_parens; i++) {
		if (leftmost_parens[i] > rightmost_stars[extra_parens-1 - i]) return false;
	}
	return true;
}

int main() {
	string inp;
	while (cin >> inp) {
		if (is_balanced(inp))
			cout << "String is balanced." << endl;
		else
			cout << "Not balanced." << endl;
	}
}
