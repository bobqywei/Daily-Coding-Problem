#include <iostream>
#include <stack>

using namespace std;

class Queue {
	stack<int> stack1;
	stack<int> stack2;

public:
	void enqueue(int i) {
		stack1.push(i);
	}

	int dequeue() {
		// assert(!stack.empty())
		while (stack1.size() != 1) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		int val = stack1.top();
		stack1.pop();

		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return val;
	}
};

int main() {
	Queue q = Queue();
	q.enqueue(5);
	q.enqueue(4);
	cout << q.dequeue() << endl;
	q.enqueue(3);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
}