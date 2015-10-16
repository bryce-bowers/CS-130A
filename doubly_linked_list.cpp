#include "doubly_linked_list.h"
template <class NodeType>
DoublyLinkedList<NodeType>::DoublyLinkedList() {
	head = NULL;
}

template <class NodeType>
DoublyLinkedList<NodeType>::~DoublyLinkedList() {
	Node<NodeType>* tmp;
	while (head) {
		tmp = head;
		head = head->GetNext();
		delete tmp;
	}
}

template <class NodeType>
void DoublyLinkedList<NodeType>::Add(NodeType* node) {
	Node<NodeType>* tmp = head;
	if (!head)  {
	head = new Node<NodeType>(node);
	return;
	}
	while (tmp->GetNext()) {
		 tmp = tmp->GetNext();
	}
	if (node) {
		Node<NodeType>* n = new Node<NodeType>(node);
		tmp->SetNext(n);
		n->SetPrev(tmp);  
	}
}

template <class NodeType>
void DoublyLinkedList<NodeType>::Remove(NodeType* node) {
	Node<NodeType>* tmp = head;
	while (tmp) {
		if (tmp->GetVal() == node) {
			Node<NodeType>* prev = tmp->GetPrev();
			Node<NodeType>* next = tmp->GetNext();
			if (prev) prev->SetNext(next);
			if (next) next->SetPrev(prev);
			if (tmp == head) head = head->GetNext();
			delete tmp;
			return;
		}
		 tmp = tmp->GetNext();
	}
}



template <class NodeType>
Node<NodeType>* DoublyLinkedList<NodeType>::GetHead(void) {
	if (head) return head;
	return NULL;  
}

