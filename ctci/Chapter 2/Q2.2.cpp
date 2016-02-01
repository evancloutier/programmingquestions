/* Implement an algorithm to find the kth to last element of a singly
linked list */

#include <iostream>
#include <string>
#include "linkedlist.h"
#include "linkedlist.cpp"

Node* ktoLast(Node* head, int k) {
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
	std::cout << ktoLast(myList->head, 4)->data << std::endl;
	delete myList;

	return 0; 
}