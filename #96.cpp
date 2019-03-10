#include<iostream>
#include<vector>

using namespace std;

template<class T>
void print_vector(vector<T>& v) {
	for (T i : v) {
		cout << i << " ";
	}
	cout << endl;
}

vector<vector<int>*>* get_all_permutations(vector<int>* remaining) {
	vector<vector<int>*>* ret = new vector<vector<int>*>;
	if (remaining->size() == 1) {
		vector<int>* temp = new vector<int>;
		temp->push_back((*remaining)[0]);
		ret->push_back(temp);
		return ret;
	}

	for (int i = 0; i < remaining->size(); i++) {
		vector<int>* without_i = new vector<int>;
		for (int j = 0; j < remaining->size(); j++) {
			if (j != i) without_i->push_back((*remaining)[j]);
		}

		vector<vector<int>*>* permutations = get_all_permutations(without_i);
		for (vector<int>* v : *permutations) {
			vector<int>* temp = new vector<int>;
			temp->push_back((*remaining)[i]);
			for (int i : *v) {
				temp->push_back(i);
			}
			free(v);
			ret->push_back(temp);
		}

		free(without_i);
		free(permutations);
	}
	return ret;
}

int main() {
	vector<int> init({1,2,3,4});
	vector<vector<int>*>* permutations = get_all_permutations(&init);

	for (vector<int>* v : *permutations) {
		cout << "[";
		for (int i : *v) {
			cout << i << " ";
		}
		cout << "]" << endl;
	}
	cout << permutations->size() << " permutations." << endl;
}