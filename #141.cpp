#include<iostream>
#include<assert.h>
#include<cstdlib>
#include<vector>
using namespace std;

class ThreeStacks { 
	int *list; // Single list implementation of three stacks
	int size;
	int middle_stack_start; // start index of middle stack
	vector<int> stack_top{-1,-1,-1}; // index of the top of each stack

	// Compute the start index of the middle stack that results in best balance
	int compute_middle_stack_start() {
		int mid_stack_size = (stack_top[1] == -1 ? 1 : stack_top[1]-middle_stack_start+1);
		// left and right mark the available space in the array
		int left = stack_top[0] + 1;
		int right = (stack_top[2] != -1 ? stack_top[2] : size) - 1;
		// adjust for size of middle stack
		right -= (mid_stack_size-1);
		// return negative if no possible start index (array is full)
		if (right < left) return -1;

		return left + (right-left+1)/2;
	}

	// Try to make more space in list by moving middle stack
	// Returns true on success, o/w false
	bool make_space() {
		// Get new start index for middle stack
		int new_start_index = compute_middle_stack_start();
		// Failure if no possible start index
		if (new_start_index == -1) {
			cout << "List is full" << endl;
			return false;
		}

		int mid_stack_size = stack_top[1]-middle_stack_start+1;
		// Move the entire middle stack to the new location
		if (new_start_index > middle_stack_start) {
			int diff = new_start_index - middle_stack_start;
			for (int i = middle_stack_start+mid_stack_size-1; i >= middle_stack_start; i--) {
				list[i+diff] = list[i];
			}
			stack_top[1] += diff;
		
		} else if (new_start_index < middle_stack_start) {
			int diff = middle_stack_start - new_start_index;
			for (int i = middle_stack_start; i <= middle_stack_start+mid_stack_size-1; i++) {
				list[i-diff] = list[i];
			}
			stack_top[1] -= diff;
		}
		middle_stack_start = new_start_index;
		// Success
		return true;
	}

public:	
	ThreeStacks(int n) {
		list = new int[n];
		size = n;
	}

	void print() {
		if (stack_top[0] != -1) {
			cout << "Stack 1 (0 to " << stack_top[0] << "): ";
			for (int i = 0; i <= stack_top[0]; i++) {
				cout << list[i] << " ";
			}
			cout << endl;
		} 
		if (stack_top[1] != -1) {
			cout << "Stack 2 (" << middle_stack_start << " to " << stack_top[1] << "): ";
			for (int i = middle_stack_start; i <= stack_top[1]; i++) {
				cout << list[i] << " ";
			}
			cout << endl;
		}
		if (stack_top[2] != -1) {
			cout << "Stack 3 (" << stack_top[2] << " to " << size-1 << "): ";
			for (int i = size-1; i >= stack_top[2]; i--) {
				cout << list[i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int pop(int stack_num) {
		// Make sure that the stack is not empty
		assert(stack_top[stack_num-1] != -1);
		int temp = stack_top[stack_num-1];
		
		if (stack_num == 3) {
			stack_top[2]++;
			// set to -1 if right stack becomes empty
			if (stack_top[2] == size) stack_top[2] = -1;
		} else {
			stack_top[stack_num-1]--;
			// set to -1 if middle stack becomes empty
			if (stack_num == 2 && stack_top[1] < middle_stack_start) stack_top[1] = -1;
		}
		// Return the value that was popped
		return list[temp];
	}

	void push(int item, int stack_num) {
		if (stack_num == 3) {
			// save previous index in case push is invalid
			int prev_index = stack_top[2];
			// new stack top after push
			stack_top[2] = (stack_top[2] != -1 ? stack_top[2]-1 : size-1);
			
			// try to make space if right stack overlaps with middle stack
			if (stack_top[2] == stack_top[1]) {
				if (!make_space()) { 
					stack_top[2] = prev_index;
					return;
				}

			// array must be full if right stack overlaps with left stack
			} else if (stack_top[2] == stack_top[0]) {
				cout << "List is full" << endl;
				stack_top[2] = prev_index;
				return;
			}
		
		} else if (stack_num == 2) {
			// save previous index
			int prev_index = stack_top[1];
			// if middle stack is empty, try to compute start index
			// otherwise just increase stack top
			if (stack_top[1] == -1) {
				int new_start_index = compute_middle_stack_start();
				if (new_start_index == -1) {
					cout << "List is full" << endl;
					return;
				}
				middle_stack_start = new_start_index;
				stack_top[1] = middle_stack_start;
			} else {
				stack_top[1]++;
			}

			// try to make space if middle stack overlaps now with right stack
			if (stack_top[2] == stack_top[1]) {
				if (!make_space()) {
					stack_top[1] = prev_index;
					return;
				}
			}

		} else if (stack_num == 1) {
			// save previous index
			int prev_index = stack_top[0];
			// new stack top after push
			stack_top[0] = (stack_top[0] != -1 ? stack_top[0]+1 : 0);
			
			// try to make space if left stack overlaps with middle stack
			if (stack_top[1] != -1 && stack_top[0] == middle_stack_start) {
				if (!make_space()) {
					stack_top[0] = prev_index; 
					return;
				}

			// array must be full if left stack overlaps with right stack
			} else if (stack_top[0] == stack_top[2]) {
				cout << "List is full" << endl;
				stack_top[0] = prev_index;
				return;
			}
		}
		// Finally, assign value to newly allocated slot
		list[stack_top[stack_num-1]] = item;
	}
};

int main() {
	ThreeStacks s(10);
	s.push(4,1);
	s.print();
	s.push(5,2);
	s.print();
	s.push(6,3);
	s.print();
	s.push(7,2);
	s.print();
	s.push(8,2);
	s.print();
	s.push(9,2);
	s.print();
	s.push(10,2);
	s.print();
	s.push(11,2);
	s.print();
	s.push(12,2);
	s.print();
	s.push(13,2);
	s.print();
	s.push(14,2);
	s.print();
}