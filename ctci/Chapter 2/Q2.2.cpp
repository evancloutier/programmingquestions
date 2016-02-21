/* Implement an algorithm to find the kth to last element of a singly
linked list */

#include <iostream>
#include <string>
#include "linkedlist.h"
#include "linkedlist.cpp"

Node* kToLast(Node* head, int k) {
	// Check if the list is empty
	if (head == NULL)
		return NULL;

	// Set the head to be the current node
	Node* current = head;

	// First we must find the length of the list
	int length = 0;
	while (current) {
		length++;
		current = current->next;
	}

	// Reset to head now that we have the length
	current = head;

	// Check if k is inside the bounds of the list
	if (k > length || k < 1)
		return NULL;

	// Finding the value of the kth element
	int count = 0;
	while (length - count != k) {
		count++;
		current = current->next;
	}
	return current;
}

Node* kToLastRunner(Node* head, int k) {
	// First we'll check if the list is empty
	if (head == NULL)
		return NULL;

	// And let's check if k is an appropriate value
	if (k <= 0)
		return NULL;

	// Next we'll create two nodes to traverse the list
	Node* n1 = head;
	Node* n2 = head;

	// Let's move n2 k nodes into the list
	for (int i = 0; i < k - 1; i++) {
		if (n2 == NULL)
			return NULL;
		n2 = n2->next;
	}

	if (n2 == NULL)
		return NULL;

	// Now we can move n1 and n2 at the same pace
	while (n2->next != NULL) {
		n1 = n1->next;
		n2 = n2->next;
	}
	return n1;
}

int main() {
	// Creating a linked list
	LinkedList* myList = new LinkedList();
	myList->insert(5);
	myList->insert(6);
	myList->insert(12);
	myList->insert(11);
	myList->insert(16);
	myList->insert(16);
	myList->insert(27);
	myList->insert(25);
	myList->insert(11);

	std::cout << "The original list is: ";
	myList->display();

	std::cout << "The 4th to last element is: ";
	std::cout << kToLast(myList->head, 4)->data << std::endl;
	std::cout << "The 4th to last element is: ";
	std::cout << kToLastRunner(myList->head, 4)->data << std::endl;

	delete myList;

	return 0; 
}