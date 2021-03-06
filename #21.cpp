#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int roomsNeeded(vector<pair<int, int>> &times){
	// Make list of all events and their corresponding times
	vector<pair<int, int>> events;
	for (pair<int, int> p : times) {
		events.push_back(make_pair(p.first, 1)); // start event
		events.push_back(make_pair(p.second, -1)); // end event
	}

	// sort the events in order based on time
	sort(events.begin(), events.end());

	int roomsUsed = 0;
	int maxRooms = 0;

	for (pair<int, int> p : events) {
		// increments or decrements depending on whether event is start or end
		roomsUsed += p.second;
		maxRooms = max(roomsUsed, maxRooms);
	}

	return maxRooms;
}

int main() {
	string in;
	cin >> in;
	int n = stoi(in);

	vector<pair<int, int>> times;
	for (int i = 0; i < n; i++) {
		cin >> in;
		int start = stoi(in);
		cin >> in;
		int end = stoi(in);

		times.push_back(make_pair(start, end));
	}

	cout << "Classrooms Needed: " << roomsNeeded(times) << endl;
}