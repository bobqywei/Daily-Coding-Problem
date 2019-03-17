#include<iostream>
#include<unordered_map>
#include<string>
#include<stdlib.h>
#include<sstream>

using namespace std;

class TimeMap {
	unordered_map<int, unordered_map<int, int>> timepoints;

public:
	void set(int key, int value, int time) {
		if (timepoints.find(key) == timepoints.end()) {
			unordered_map<int, int> map;
			timepoints[key] = map;
		}
		timepoints[key][time] = value;
	}

	int get(int key, int time) {
		unordered_map<int, int>& val_at_time = timepoints[key];
		int most_recent = -1;
		for (pair<int, int> time_val : val_at_time) {
			if (time_val.first < time) most_recent = max(most_recent, time_val.first);
			else if (time_val.first == time) return time_val.second;
		}
		return (most_recent == -1) ? -1 : val_at_time[most_recent];
	}
};

int main() {
	TimeMap map;
	string inp;
	while (getline(cin, inp)) {
		istringstream ss(inp);
		string token;
		int time, value, key;
		ss >> token;
		if (token == "set") {
			ss >> token;
			key = stoi(token);
			ss >> token;
			value = stoi(token);
			ss >> token;
			time = stoi(token);
			map.set(key, value, time);
		} else if (token == "get") {
			ss >> token;
			key = stoi(token);
			ss >> token;
			time = stoi(token);
			
			int result = map.get(key, time);
			if (result == -1) cout << "null" << endl;
			else cout << result << endl;
		}
	}
}