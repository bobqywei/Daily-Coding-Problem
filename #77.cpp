#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void printVector(vector<pair<int, int>> &v) {
	for (pair<int, int> p : v) {
		cout << "[" << p.first << "," << p.second << "] ";
	}
	cout << endl;
}

bool overlap(int a1, int b1, int a2, int b2) {
	return (a2 >= a1 && a2 <= b1) || (b2 >= a1 && b2 <= b1) || (a1 >= a2 && a1 <= b2) || (b1 >= a2 && b1 <= b2);
}

vector<pair<int, int>> *removeOverlap(vector<pair<int, int>> &v) {
	vector<pair<int, int>> *noOverlap = new vector<pair<int, int>>;
	sort(v.begin(), v.end(), [](pair<int, int> &left, pair<int, int> &right) {
		return left.first < right.first;
	});

	pair<int, int> prev = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (!overlap(prev.first, prev.second, v[i].first, v[i].second)) {
			noOverlap->push_back(make_pair(prev.first, prev.second));
			prev = v[i];
		} else {
			prev = make_pair(min(prev.first, v[i].first), max(prev.second, v[i].second));
		}
	}
	noOverlap->push_back(make_pair(prev.first, prev.second));
	return noOverlap;
}

int main() {
	string inp;
	cin >> inp;
	int n = stoi(inp);
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		cin >> inp;
		int a = stoi(inp);
		cin >> inp;
		int b = stoi(inp);
		v.push_back(make_pair(a, b));
	}

	vector<pair<int, int>> *noOverlap = removeOverlap(v);
	printVector(*noOverlap);
}