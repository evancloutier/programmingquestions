/* Imagine a (literal) stack of plates. If the stack gets too high,
it might topple. In real life, we would likely start a new stack
when the previous stack exceeds some threshold. Implement a data 
structure SetOfStacks that mimics this. SetOfStacks should be composed
of several stacks and should create a new stack once the previous one
exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should 
behave identically to a single stack. */

#include <iostream>
#include <stack>
#include <climits>
#define STACK_NUMBER 100

// Come back to this question

class SetOfStacks {
private:
	std::stack<int> *myStack;
	int threshold;
	int currentStack;
public:
	SetOfStacks() {
		threshold = 10;
		myStack = new std::stack<int>[STACK_NUMBER];
		currentStack = 0;
	}

	void push(int data) {
		if(myStack[currentStack].size() >= threshold) {
			currentStack++;
		}
		myStack[currentStack].push(data);
	}

	void pop() {
		if (myStack[currentStack].empty()) {
			if (currentStack == 0) {
				std::cout << "The stack is empty" << std::endl;
				return;
			}
			currentStack--;
		}
		myStack[currentStack].pop();
	}

	int top() {
		if (myStack[currentStack].empty()) {
			if (currentStack == 0) {
				if (currentStack == 0) {
					return INT_MIN;
				}
				currentStack--;
			}
		}
		return myStack[currentStack].top();
	}

	bool empty() {
		if (currentStack == 0) {
			return myStack[currentStack].empty();
		}
		else
			return false;
	}

	void popAt(int index) {
		if (myStack[index].empty()) {
			std::cout << "Substack " << index << " is empty" << std::endl;
			return;
		}
		myStack[index].pop();
	}
};

int main() {
	SetOfStacks myStack;
	
	for (int i = 0; i < 100; i++) {
		myStack.push(i);
		std::cout << i << std::endl;
	}

	for (int i = 0; i < 101; i++) {
		std::cout << myStack.top() << std::endl;
		myStack.pop();
	}

	return 0;
}





