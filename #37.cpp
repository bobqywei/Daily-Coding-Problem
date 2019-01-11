#include <iostream>
#include <unordered_set>
#include <vector>
#include <deque>

using namespace std;

vector<unordered_set<int> *> *powerSet(unordered_set<int> &S) {
	vector<unordered_set<int> *> *P = new vector<unordered_set<int> *>;
	P->push_back(new unordered_set<int>);

	for (int i : S) {
		deque<unordered_set<int> *> Q;

		for (unordered_set<int> *set : *P) {
			unordered_set<int> *newSet = new unordered_set<int>(*set);
			newSet->insert(i);
			Q.push_back(newSet);
		}

		while (!Q.empty()) {
			P->push_back(Q.front());
			Q.pop_front();
		}
	}

	return P;
}

int main() {
	unordered_set<int> S({1, 2, 3});
	vector<unordered_set<int> *> *P = powerSet(S);

	cout << "{ " << endl;
	for (unordered_set<int> *set : *P) {
		cout << "\t" << "{";
		for (int i : *set) {
			cout << i << ", ";
		}
		cout << "}" << endl;
	}
	cout << "}" << endl;
}