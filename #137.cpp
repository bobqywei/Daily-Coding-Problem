#include<iostream>

using namespace std;

class BitArray {
	bool *array;
public:
	void init(int size) {
		array = new bool[size];
	}
	void set(int i, int val) {
		array[i] = (bool)val;
	}
	int get(int i) {
		return (int)array[i];
	}
};

int main() {
	BitArray arr;
	arr.init(3);
	arr.set(0, 1);
	arr.set(1, 1);
	arr.set(2, 0);
	cout << arr.get(0) << ", " << arr.get(1) << ", " << arr.get(2) << endl;
}