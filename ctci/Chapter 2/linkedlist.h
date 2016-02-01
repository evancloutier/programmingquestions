// Linked List Header File
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct Node {
	int data;
	Node* next;
};

class LinkedList {
public:
	Node *head;
	LinkedList();
	~LinkedList();
	void display();
	void insert(int value);
	void createCycle(); // infinite cycle
private:
	Node *tail;
};

#endif