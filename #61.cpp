#include <iostream>
#include <string>

using namespace std;

int runtime = 0;

long long pow(int x, int y) {
	long long result = 1;
	int curr_pow = 0;

	long long multiplier = x;
	int mult_pow = 1;

	while (curr_pow < y) {
		if (result == 1) {
			result *= multiplier;
			curr_pow += mult_pow;
			runtime++;
		} else if (curr_pow + mult_pow <= y) {
			curr_pow += mult_pow;
			result *= multiplier;
			multiplier *= multiplier;
			mult_pow *= 2;
			runtime++;
		} else {
			multiplier = x;
			mult_pow = 1;
		}
	}
	
	return result;
}

int main() {
	string inp;
	while (cin >> inp) {
		int b = stoi(inp);
		cin >> inp;
		int e = stoi(inp);
		cout << b << " ** " << e << " = " << pow(b, e) << endl << runtime << endl;
		runtime = 0;
	}
}