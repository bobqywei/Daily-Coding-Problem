#include<string>
#include<iostream>
#include<cstdlib>

using namespace std;

string pad_string(const string& s) {
	string output = "";
	for (char c : s) {
		output += "_";
		output += c;
	}
	output += "_";
	return output;
}

bool recursive_check(const string& s, const int num_deletions, int left, int right) {
	// Palindrome is possible if all characters are verified
	if (left == -1 and right == s.length()) return true;

	// Check if string can be balanced by removing as many characters as possible
	int num_left = left + 1;
	int num_right = s.length() - right;
	if (min(num_left, num_right) < max(num_left, num_right) - num_deletions*2) return false;

	// Continue if current characters match
	if (left >= 0 && right < s.length() && s[left] == s[right]) 
		return recursive_check(s, num_deletions, left-1, right+1);
	// Check if any deletions left over if chars don't match
	else if (num_deletions == 0) 
		return false;

	// Try removing chars to left and right
	bool removeLeft = recursive_check(s, num_deletions-1, left-2, right);
	bool removeRight = recursive_check(s, num_deletions-1, left, right+2);
	return removeLeft || removeRight;
}

bool can_become_palindrome(string s, const int num_deletions) {
	if (s.length() <= 1) return true;
	s = pad_string(s);
	for (int i = 1; i < s.length(); i++) {
		if (recursive_check(s, num_deletions, i-1, i+1)) return true;
	}
	return false;
}

int main() {
	bool result = can_become_palindrome("awatzerrfetawx", 4);
	cout << (result ? "True" : "False") << endl;
}