/* How would you design a stack which, in addition to push and pop,
also has a function min which returns the minimum element? Push, pop,
and min should all operate in O(1) time.

So in this question we are utilizing two stacks, our regular stack
and a stack that holds the minimums. */

#include <iostream>
#include <stack>
#include <climits>

class StackWithMin {
private:
	std::stack<int> s1, s2;
public:
	void push(int x) {
		// Here we are pushing our element onto the regular stack
		s1.push(x);
		// Here we check if the minimum element is greater than x
		// If so, push it
		if (min() >= x) {
			s2.push(x);
		}
	}

	void pop() {
		// Here we check if our element is a minimum
		// If so, we pop it as well
		if (min() == s1.top()) {
			s2.pop();
		}
		// Here we pop our regular stack element
		s1.pop();
	}

	int min() {
		// If our minimum stack is empty, we return an error value
		if (s2.empty()) {
			return INT_MAX;
		}
		// Otherwise we simply return our minimum element
		return s2.top();
	}

	bool empty() {
		// Simply checking if our stack is empty
		return s1.empty();
	}

	int top() {
		// Simply returning the top value
		return s1.top();
	}
};

int main() {

	StackWithMin myStack;
	int myArray[] = {6, 3, 5, 2, 2, 9, 2, 8, 1, 1};
	
	for (int i = 0; i < 10; i++) {
		myStack.push(myArray[i]);
		std::cout << myArray[i] << " " << myStack.min() << std::endl;
	}

	for (int i = 0; i < 10; i++) {
		myStack.pop();
		std::cout << i << " " << myStack.min() << std::endl;
	}

	return 0;
}