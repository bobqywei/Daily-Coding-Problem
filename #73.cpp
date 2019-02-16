#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node (int v) {
		val = v;
		next = nullptr;
	}
};

struct LinkedList {
	Node* head;

	LinkedList (int arr[], int size) {
		head = new Node(arr[0]);
		Node* curr = head;
		for (int i = 1; i < size; i++) {
			Node* temp = new Node(arr[i]);
			curr->next = temp;
			curr = temp;
		}
	}

	void print() {
		Node* curr = head;
		while (curr != nullptr) {
			cout << curr->val << "->";
			curr = curr->next;
		}
		cout << endl;
	}
};

void reverseLinkedList(LinkedList* list) {
	Node* curr = list->head;
	Node* prev = nullptr;
	while (curr != nullptr) {
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	list->head = prev;
}

int main() {
	int arr[] = {0,1,2,3,4,5};
	LinkedList* list = new LinkedList(arr, sizeof(arr)/sizeof(arr[0]));
	reverseLinkedList(list);
	list->print();
}