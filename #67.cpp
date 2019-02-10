#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
#include <sstream>

using namespace std;

class LFUCache {
	// key -> (value, frequency)
	unordered_map<string, pair<int, int>> vals;
	unordered_map<int, unordered_set<string> *> counts;
	int size;
	int lowestFreq;

	void incFreq(string key) {
		int prevCount = vals[key].second;
		counts[prevCount]->erase(key);
		vals[key].second = prevCount + 1;

		if (counts.find(prevCount + 1) == counts.end()) {
			unordered_set<string> *s = new unordered_set<string>;
			s->insert(key);
			counts[prevCount + 1] = s;
		} else {
			counts[prevCount + 1]->insert(key);
		}

		if (prevCount == lowestFreq && counts[prevCount]->size() == 0)
			lowestFreq++;
	}

public:
	LFUCache(int n) {
		assert(n > 0);
		size = n;
		lowestFreq = -1;
	}

	int get(string key) {
		assert(vals.size() > 0);
		if (vals.find(key) == vals.end()) return -1;

		incFreq(key);
		return vals[key].first;
	}

	void set(string key, int val) {
		if (vals.find(key) != vals.end()) {
			vals[key].first = val;
			incFreq(key);
		} else {
			if (vals.size() == size) {
				unordered_set<string>::iterator it = counts[lowestFreq]->begin();
				string toRemove = *it;
				counts[lowestFreq]->erase(it);
				vals.erase(toRemove);
			}

			vals[key] = make_pair(val, 1);
			lowestFreq = 1;

			if (counts.find(1) == counts.end()) {
				unordered_set<string> *s = new unordered_set<string>;
				s->insert(key);
				counts[1] = s;
			} else {
				counts[1]->insert(key);
			}
		} 
	}

};

int main() {
	LFUCache cache = LFUCache(3);

	string inp;
	while (cin >> inp) {
		string token;
		istringstream ss(inp);
		while (getline(ss, token, ',')) {
			if (token == "get") {
				string key;
				getline(ss, key, ',');
				cout << cache.get(key) << endl;
			} else if (token == "set") {
				string key;
				getline(ss, key, ',');
				getline(ss, token, ',');
				int val = stoi(token);
				cache.set(key, val);
			}
		}
	}
}