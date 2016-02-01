/* Implement an algorithm to delete a node in the middle of a singly linked list, given only
access to that node. */

#include <iostream>
#include <string>
#include "linkedlist.h"
#include "linkedlist.cpp"

bool removeNode(Node* node) {
	if (node == NULL || node->next == NULL) {
		return false;
	}

	// Creating a temporary node to shift data
	Node *temp = node->next;
	// Overwriting the node data with the temporary data (i.e. the next node)
	node->data = temp->data;
	// Overwriting the node data with the temporary data (i.e. the next node location)
	node->next = temp->next;
	// Deleting the temporary node after shifting the data
	delete temp;

	return true;
}

int main() {
	LinkedList* myList = new LinkedList();
    myList->insert(5);
    myList->insert(7);
    myList->insert(12);
    myList->insert(7);
    myList->insert(16);
    myList->insert(18);
    myList->insert(25);
    myList->insert(11);
    myList->insert(5);

    // Finding random node in the list
    Node* temp = myList->head->next->next->next;

    std::cout << "The original list is: ";
    myList->display();

    std::cout << "Removing node with value: " << temp->data << std::endl;
    removeNode(temp);

    std::cout << "The new list is: ";
    myList->display();

    delete myList;

    return 0;
}