/* Given a circular linked list, implement an algorithm which
returns the node at the beginning of the loop. */

#include <iostream>
#include <string>
#include "linkedlist.h"
#include "linkedlist.cpp"

Node* findStartCycle(Node* head) {
	// Check that the list is not empty
	if (head == NULL)
		return NULL;

	// Creating two nodes to traverse through linked list
	Node* slow = head;
	Node* fast = head;

	// Iterate through list ensuring it is not empty
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	// Ensuring that our list indeed has a loop
	if (fast == NULL || fast->next == NULL)
		return NULL;


	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main() {
	LinkedList* myList = new LinkedList();
    myList->insert(5);
    myList->insert(3);
    myList->insert(6);
    myList->insert(8);
    myList->insert(1);
    myList->insert(2);

    std::cout << "For the list: ";
    myList->display();
    std::cout << "A cycle begins at value: ";

    // create a cycle in the list
    myList->createCycle();

    Node* beginCycle = findStartCycle(myList->head);
    std::cout << beginCycle->data << std::endl;

    return 0;
 
}