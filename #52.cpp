#include <iostream>
#include <deque>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class LRUCache {
	int maxSize;
	deque<string> Q;
	unordered_map<string, pair<int, deque<string>::iterator>> m;

	void update(string key) {
		Q.erase(m[key].second);
		Q.push_front(key);
		m[key] = make_pair(m[key].first, Q.begin());
	}

public:
	LRUCache(int n) {
		maxSize = n;
	}

	int get(string key) {
		if (m.find(key) == m.end())
			return -1;
		update(key);
		return m[key].first;
	}

	void set(string key, int value) {
		if (m.find(key) != m.end()) {
			update(key);
		} else if (Q.size() == maxSize) {
			m.erase(Q.back());
			Q.pop_back();
			Q.push_front(key);
		} else {
			Q.push_front(key);
		}
		m[key] = make_pair(value, Q.begin());
	}
};

int main() {
	LRUCache cache = LRUCache(3);

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