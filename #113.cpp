#include<string>
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void swap_chars_(string& s, int left, int right, int n) {
	for (int i = 0; i < n; i++) {
		char temp = s[left + i];
		s[left + i] = s[right + i];
		s[right + i] = temp; 
	}
}

void reverse_(string& s, int left, int right) {
	for (int i = 0; i < (right - left + 1) / 2; i++) {
		char temp = s[left + i];
		s[left + i] = s[right - i];
		s[right - i] = temp;
	}
}

void rotate_left_(string& s, int left, int right, int n) {
	reverse_(s, left, left+n-1);
	reverse_(s, left+n, right);
	reverse_(s, left, right);
}

void reverse_words_(string& s) {
	vector<int> word_lens;
	int len = 0;
	// Fill vector with word lengths
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			len += 1;
		} else {
			word_lens.push_back(len);
			len = 0;
		}
	}
	word_lens.push_back(len);

	// Window size
	int left = 0;
	int right = s.length() - 1;
	// Flip direct pairs of words in the sentence
	for (int i = 0; i < word_lens.size() / 2; i++) {
		int len_a = word_lens[i];
		int len_b = word_lens[word_lens.size()-1-i];

		// Swap all possible characters
		int min_len = min(len_a, len_b);
		swap_chars_(s, left, right - len_b + 1, min_len);

		left += min_len;
		int extra_len = abs(len_a - len_b);

		// Rotate the remaining chars from the larger word over
		// Also shrink the window form both sides
		if (len_a > len_b) {
			rotate_left_(s, left, right, extra_len);
			left += 1;
			right = right - min_len - extra_len - 1;

		} else if (len_a < len_b) {
			rotate_left_(s, left, right, (right-left+1) - extra_len);
			left = left + extra_len + 1;
			right = right - min_len - 1;

		} else {
			left += 1;
			right = right - min_len - 1;
		}
	}
}

int main() {
	string inp;
	while(getline(cin, inp)) {
		cout << "\"" << inp << "\" reversed is \"";
		reverse_words_(inp);
		cout << inp << "\"" << endl;
	}
}