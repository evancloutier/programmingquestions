/* Write a program to sort a stack in ascending order (with 
biggest items on top). You may use at most one additional stack 
to hold items, but you may not copy the elements into any other data
structure. The stack supports the following operations: push, pop, peek,
and isEmpty. */

#include <iostream>
#include <stack>

void sortStack(std::stack<int> *st) {
	// Use a second stack, where the top contains the smallest element
	std::stack<int> sorted; 

	// This process continues until the original stack is empty
	while(!(*st).empty()) {
		// Saving the top of the stack as a temporary variable
		int tmp = (*st).top();
		// Popping the variable
		(*st).pop();
		// Continue to pop values until tmp is less than the value
		while(!sorted.empty() && tmp > sorted.top()) {
			// Pushing the value to the first stack
			(*st).push(sorted.top());
			// Popping the value off of the sorted stack
			sorted.pop();
		}
		// Push the temp value onto the stack
		sorted.push(tmp);
	}

	// Put into ascending order by pushing into original stack
	while(!sorted.empty()) {
		(*st).push(sorted.top());
		sorted.pop();
	}
}

int main() {
	std::stack<int> myStack;
	int arr[] = {6, 4, 8, 9, 10, 99, 7, 1, 0};

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		myStack.push(arr[i]);
	}
	sortStack(&myStack);

	while(!myStack.empty()) {
		std::cout << myStack.top() << std::endl;
		myStack.pop();
	}
}
