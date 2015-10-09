#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <stddef.h>
template <class NodeType>
class Node {
private:
	Node* prev;
	Node* next;
	NodeType* val;
public:
	Node(NodeType* value) {
		val = value;
		prev = NULL;
		next = NULL;
	}
	~Node() {
		delete val;
	}

	void SetPrev(Node* node) {prev = node;};
	Node* GetPrev() {return prev;};
	void SetNext(Node* node) {next = node;};
	Node* GetNext() {return next;};
	void SetVal(NodeType* val) {val = val;};
	NodeType* GetVal() {return val;};
};

template <class NodeType>
class DoublyLinkedList { 
private:
	Node<NodeType>* head; // May need tail, depending on what 2.d asks for.
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	
	void Add(NodeType* node);
	void Remove(NodeType* node);
	NodeType* Traverse(void); // Don't understand the question.	
};
#include "doubly_linked_list.cpp"
#endif
