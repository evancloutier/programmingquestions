/* Implement a MyQueue class which implements a queue using two stacks. */

#include <iostream>
#include <stack>
#include <climits>

class MyQueue {
private:
	std::stack<int> inbox, outbox;
public:
	void enqueue(int data) {
		inbox.push(data);
	}

	int dequeue() {
		int returnVal;
		if (outbox.empty()) {
			while (!inbox.empty()) {
				outbox.push(inbox.top());
				inbox.pop();
			}
		}
		returnVal = outbox.top();
		outbox.pop();
		return returnVal;
	}
};

int main() {
	MyQueue testQueue;

	for (int i = 0; i < 10; i++) {
		testQueue.enqueue(i);
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << testQueue.dequeue() << " ";
	}
}