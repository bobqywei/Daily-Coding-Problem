#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<climits>
#include<cstdlib>

using namespace std;

int minimum_sequential_distance(string w1, string w2, const vector<string>& words) {
	int min_distance = INT_MAX;
	int first_index = -1;
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == w1)
			first_index = i;
		else if (words[i] == w2 && first_index != -1) {
			min_distance = min(min_distance, i - first_index - 1);
			first_index = -1;
		}
	}
	return min_distance;
}

int shortest_distance_between_words(string w1, string w2, string context) {
	// split sentence into words
	vector<string> words;
	istringstream ss(context);
	string token;
	while(ss >> token) {
		words.push_back(token);
	}

	// find min distance from instance of w1 to instance of w2
	int min_w1_to_w2 = minimum_sequential_distance(w1, w2, words);
	// find min distance from instance of w2 to instance of w1
	int min_w2_to_w1 = minimum_sequential_distance(w2, w1, words);
	// return overall minimum
	return min(min_w2_to_w1, min_w1_to_w2);
}

int main() {
	string sentence = "world cat dog cat hello cat dog world cat";
	string w1 = "hello";
	string w2 = "world";
	cout << shortest_distance_between_words(w1, w2, sentence) << endl;
}