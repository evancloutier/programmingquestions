// Write code to remove duplicates from an unsorted linked list.

#include <iostream>
#include <unordered_map>
#include <string>
#include "linkedlist.h"
#include "linkedlist.cpp"

// Time complexity for this function is O(n)
void removeDuplicatesHash(Node* head) {
	if (head == NULL) 
		return;

	// Create hash map to store elements
	std::unordered_map<int,bool> map;
	// Set head to be the current node
	Node* current = head;
	// Hash the current node data to be true
	map[current->data] = 1;
	// While another node still exists
	while(current->next) {
		// If the data value has not been hashed
		if (map[current->next->data] == 0) {
			// Hash it
			map[current->next->data] = 1;
			// Get our next element
			current = current->next;
		}
		else {
			// Create temporary node (for the purpose of reporting data)
			Node *temp = current->next;
			// Continue to next node
			current->next = current->next->next;
			std::cout << "Duplicate found: " << temp->data << std::endl;
			delete temp;
		}
	}
}

// Time complexity for this function is O(n^2)
void removeDuplicatesRunner(Node* head) {
	// Check if there is anything in the linked list
	if (head == NULL) {
		return;
	}
	// Set the head to be the current node
	Node* current = head;
	// Create a runner node to traverse through the linked list
	Node* runner;
	// While current isn't a NULL value
	while (current) {
		// Set our runner equal to the current node
		runner = current;
		// Check if there is another node
		while (runner->next) {
			// Checking for duplicates
			if (current->data == runner->next->data) {
				// Creating a temporary node to delete the data
				Node* temp = runner->next;
				// Increment the runner to continue searching
				runner->next = runner->next->next;
				std::cout << "Duplicate found: " << temp->data << std::endl;
				delete temp;
			}
			else {
				// Continue if no duplicate found
				runner = runner->next;
			}
		}
		// Change our current node and continue to search
		current = current->next;
	}
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
	std::cout << std::endl;

	removeDuplicatesHash(myList->head);

	std::cout << "The list without duplicates is: ";
	myList->display();
	std::cout << std::endl;

	delete myList;
	return 0;
}