#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<limits.h>
#include<stdlib.h>

using namespace std;

bool is_in_set(unordered_set<char>& S, char c) {
	return S.find(c) != S.end();
}

bool is_in_map(unordered_map<char, int>& M, char c) {
	return M.find(c) != M.end();
}

void inc_map(unordered_map<char, int>& M, char c) {
	if (is_in_map(M, c)) M[c] += 1;
	else M[c] = 1;
}

int next_index_with_chars(unordered_set<char>& chars, string s, int start) {
	for (int i = start; i < s.length(); i++) {
		if (is_in_set(chars, s[i])) return i;
	}
	return -1;
}

string shortest_substr_with_chars(unordered_set<char>& chars, string s) {
	int left = next_index_with_chars(chars, s, 0);
	int right = left;
	unordered_map<char, int> curr_state = {{s[left], 1}};

	string shortest = s; 
	
	while(right < s.length() - 1) {
		// substring found with all chars present
		// update shortest if new substring is shorter
		if (curr_state.size() == chars.size() && (right-left+1) < shortest.length())
			shortest = s.substr(left, right-left+1);

		// increment window
		right++;

		// new char added is in set
		if (is_in_set(chars, s[right])) {
			inc_map(curr_state, s[right]); // add the new char to map

			// New char is same as the leftmost char in the window.
			// We can shrink the window from the left since we only
			// need 1 of each char in the substring 
			if (s[left] == s[right]) {
				// keep shrinking until found char with 1 occurence
				while (curr_state[s[left]] != 1) {
					curr_state[s[left]] -= 1;
					left = next_index_with_chars(chars, s, left+1);
				}
			}

		}
	}

	// need to check for last window
	if (curr_state.size() == chars.size() && (s.length()-left) < shortest.length())
		shortest = s.substr(left, s.length()-left);

	return ((shortest.length() == 0) ? "" : shortest);
}

int main() {
	unordered_set<char> chars({'a','e','c'});
	string s = "bdefacee";
	string ret = shortest_substr_with_chars(chars, s);
	if (ret.length() == 0) {
		cout << "No possible substring." << endl;
	} else {
		cout << ret << endl;
	}
}
