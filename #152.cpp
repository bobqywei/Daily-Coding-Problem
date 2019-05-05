#include<iostream>
#include<vector>
#include<random>
#include<cstdlib>
#include<cmath>

using namespace std;

int get_decimal_places(float f) {
	int decimal_places = 0;
	while (f != 0) {
		decimal_places++;
		f *= 10;
		f -= (int)f;
	}
	return decimal_places;
}

int rand_probability(vector<int>& values, vector<float>& probabilities) {
	// find the maximum decimal places in the probabilities
	int max_decimal_places = 0;
	for (float f : probabilities) {
		max_decimal_places = max(max_decimal_places, get_decimal_places(f));
	}

	int rand_max = pow(10, max_decimal_places);
	int rand_num = rand() % rand_max; // random int between 0 and rand_max
	int curr_range = 0;
	for (int i = 0; i < values.size(); i++) {
		curr_range += probabilities[i] * rand_max;
		if (rand_num < curr_range) 
			return values[i];
	}
	// error, probabilities do not add up to 1
	return -1;
}

int main() {
	vector<int> values = {1,2,3,4};
	vector<float> probs = {0.1,0.5,0.2,0.2};
	for (int i = 0; i < 10; i++) {
		cout << rand_probability(values, probs) << endl;
	}
}