#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int divide(int x, int y) {
	int quotient = 0;
	while (x - y >= 0) {
		x -= y;
		quotient++;
	}
	return quotient;
}

int main() {
	string inp;
	while(getline(cin, inp)) {
		istringstream ss(inp);
		string token;
		ss >> token;
		int x = stoi(token);
		ss>> token;
		int y = stoi(token);
		cout << divide(x,y) << endl;
	}
}