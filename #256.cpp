#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void solution(vector<int>& v) {
	sort(v.begin(), v.end());
	for (int i = 1; i < v.size()-1; i+=2) {
		int tmp = v[i];
		v[i] = v[i+1];
		v[i+1] = tmp;
	}
}

int main() {
	vector<int> v;
	string s;
	getline(cin, s);
	istringstream ss(s);

	int inp;
	while(ss >> inp) {
		v.push_back(inp);
	}
	solution(v);
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}