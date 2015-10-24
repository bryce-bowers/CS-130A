#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <stddef.h>
template <class NodeType>
class Node {
private:
	Node* prev;
	Node* next;
	NodeType val;
public:
	Node(NodeType &value) {
		val = value;
		prev = NULL;
		next = NULL;
	}
	Node() {}
	~Node() {}

	void SetPrev(Node* node) {prev = node;};
	Node* GetPrev() {return prev;};
	void SetNext(Node* node) {next = node;};
	Node* GetNext() {return next;};
	void SetVal(const NodeType &value) {val = value;};
	NodeType& GetVal() {return val;};
};

template <class NodeType>
class DoublyLinkedList { 
private:
	Node<NodeType>* head; // May need tail, depending on what 2.d asks for.
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	
	void Add(NodeType& node);
	void Remove(NodeType& node);
	Node<NodeType>* GetHead(void); // Get head
	void SetHead(Node<NodeType>* node) {
		head = node;
	}	
};
#include "doubly_linked_list.cpp"
#endif
