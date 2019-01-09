#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void rearrange(vector<char> &v) {
	int curr = 0;

	for (int i = curr; i < v.size(); i++) {
		if (v[i] == 'R') {
			swap(&v[curr], &v[i]);
			curr++;
		}
	}

	for (int i = curr; i < v.size(); i++) {
		if (v[i] == 'G') {
			swap(&v[curr], &v[i]);
			curr++;
		}
	}
}

int main() {
	string inp;

	while (cin >> inp) {
		vector<char> v;
		for (char c : inp) {
			v.push_back(c);
		}

		rearrange(v);

		for (char c : v) {
			cout << c;
		}
		cout << endl;
	}
}