#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

using namespace std;

bool is_anagram(int a[], int b[]) {
    for (int i = 0; i < 256; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

vector<int> anagram_substrings(string s, string sub) {
    vector<int> anagram_indices;
    int sub_freq[256] = {0};
    int curr_freq[256] = {0};

    for (char c : sub) {
        sub_freq[c] += 1;
    }

    int left = 0;
    int right = 0;

    while(right < sub.length()) {
        curr_freq[s[right++]] += 1;
    }
    right--;

    while(right < s.length()) {
    	if (is_anagram(sub_freq, curr_freq)) anagram_indices.push_back(left);
    	curr_freq[s[left++]] -= 1;
		curr_freq[s[ min(++right, int(s.length()-1)) ]] += 1;	
    }

    return anagram_indices;
}

int main() {
    string inp;
    while (cin >> inp) {
        string s = inp;
        cin >> inp;
        string sub = inp;
        vector<int> anagrams = anagram_substrings(s, sub);
        for (int i : anagrams) {
            cout << i << ",";
        }
        cout << endl;
    }
}
