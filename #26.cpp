#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Node {
public:
	int val;
	Node* next;

	Node(int v) {
		val = v;
		next = nullptr;
	}
};

class LinkedList {
public:
	Node* head;

	LinkedList(vector<int> &v) {
		Node* curr = new Node(v[0]);
		head = curr;
		for (int i = 1; i < v.size(); i++) {
			Node* temp = new Node(v[i]);
			curr->next = temp;
			curr = temp;
		}
	}

	void print() {
		Node* curr = head;
		while (curr != nullptr) {
			cout << curr->val << ",";
			curr = curr->next;
		}
		cout << endl;
	}
};

Node* removeKthLast(Node* head, int k) {
	Node* first = head;
	Node* second = head;
	Node* prev = nullptr;

	// Iterate k times with first pointer
	for (int i = 0; i < k; i++) {
		first = first->next;
	}

	// Iterate both simultaneously until end
	while (first != nullptr) {
		first = first->next;
		prev = second;
		second = second->next;
	}

	// Second points to kth last item
	if (prev == nullptr) {
		return second->next;
	} else {
		prev->next = second->next;
		return head;
	}
}

int main() {
	int k;
	vector<int> v;
	string in;
	cin >> in;
	k = stoi(in);
	cin >> in;

	istringstream ss(in);
	string token;

	while (getline(ss, token, ',')) {
		v.push_back(stoi(token));
	}

	LinkedList *list = new LinkedList(v);
	list->head = removeKthLast(list->head, k);

	list->print();
}
