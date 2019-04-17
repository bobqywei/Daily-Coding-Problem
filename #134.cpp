#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>

using namespace std;

class SparseArray {
	unordered_map<int, int> nonzero;

public:
	SparseArray(int arr[], int size) {
		for (int i = 0; i < size; i++)
			if (arr[i] != 0) nonzero[i] = arr[i];
	}
	void set(int i, int val) {
		if (val == 0 && nonzero.find(i) != nonzero.end())
			nonzero.erase(i);
		else if (val != 0)
			nonzero[i] = val;
	}
	int get(int i) {
		if (nonzero.find(i) != nonzero.end())
			return nonzero[i];
		else
			return 0;
	}
};

int main() {
	int arr[] = {1,0,0,0,5,3,2,0,0,4};
	SparseArray a(arr, 10);
	for (int i = 0; i < 10; i++)
		cout << a.get(i) << ",";
	cout << endl;
	string inp;
	while (getline(cin, inp)) {
		istringstream ss(inp);
		ss >> inp;
		if (inp == "get") {
			ss >> inp;
			int i = stoi(inp);
			cout << "value: " << a.get(i) << endl;
		} else if (inp == "set") {
			ss >> inp;
			int i = stoi(inp);
			ss >> inp;
			int val = stoi(inp);
			a.set(i, val);
		}
	}
}
