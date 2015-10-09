#include "doubly_linked_list.h"
template <class NodeType>
DoublyLinkedList<NodeType>::DoublyLinkedList() {
	head = NULL;
}

template <class NodeType>
DoublyLinkedList<NodeType>::~DoublyLinkedList() {
	Node* tmp;
	while (head) {
		tmp = head;
		head = head->GetNext();
		delete tmp;
	}
}

template <class NodeType>
void DoublyLinkedList<NodeType>::Add(NodeType* node) {
	Node* tmp = head;
	if (!head) head = new Node(node);
	while (tmp->GetNext()) {
		 tmp = tmp->GetNext();
	}
	if (!node) {
		Node* n = new Node(node);
		tmp->SetNext(n);
		n->SetPrev(tmp);  
	}
}

template <class NodeType>
void DoublyLinkedList<NodeType>::Remove(NodeType* node) {
	Node* tmp = head;
	while (tmp) {
		if (tmp->GetVal() == node) {
			Node* prev = tmp->GetPrev();
			Node* next = tmp->GetNext();
			if (prev) prev->SetNext(next);
			if (next) next->SetPrev(prev);
			if (tmp == head) head = head->GetNext();
			delete tmp;
		}
		 tmp = tmp->GetNext();
	}
}



class DoublyLinkedList { 
private:
	NodeType* head; // May need tail, depending on what 2.d asks for.
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	
	void Add(NodeType* node);
	void Remove(NodeType* node);
	NodeType* Traverse(void); // Don't understand the question.	
};

template <class NodeType>
NodeType* DoublyLinkedList<NodeType>::Traverse(void) {
	if (head) return head->GetVal();
	return NULL; // TODO 
}
	
