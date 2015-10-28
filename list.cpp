#include "list.h"
#include <iostream>
#include "doubly_linked_list.h"
using namespace std;

template <class T>
List<T>::List() {
	linked_list = new DoublyLinkedList<T>;
	length = 0; 
}	

template <class T>
List<T>::~List() {
	delete linked_list;
}


template <class T>
bool List<T>::insert(int pos, const T & item) {
	if (pos < 0 || pos > length) return false;
	int count = 0;
	Node<T>* cur = linked_list->GetHead();
	Node<T>* node = new Node<T>;
	node->SetVal(item);
	if (pos == 0) {
		if (cur) {
			cur->SetPrev(node);
		}
		node->SetNext(cur);
		linked_list->SetHead(node);
		length ++;
		return true;
	}
	while (count < pos - 1) {
		cur = cur->GetNext();
		count ++;
	}
	Node<T>* tmp = cur->GetNext();
	cur->SetNext(node);
	node->SetPrev(cur);
	node->SetNext(tmp);
	if (tmp)
		tmp->SetPrev(node);
	length ++;
        
	return true;
}

template <class T>
bool List<T>::remove(int pos) {
	if (pos < 0 || pos >= length) return false;
	int count = 0;
	Node<T>* cur = linked_list->GetHead();
	if (pos == 0) {
		Node<T>* tmp = cur->GetNext();
		delete cur;
		if (tmp) {
			tmp->SetPrev(NULL);
		}
		linked_list->SetHead(tmp);
		length --;
		return true;
	}
	while (count < pos - 1) {
		cur = cur->GetNext();
		count ++;
	}
	Node<T>* tmp = cur->GetNext();
	Node<T>* tmp2 = tmp->GetNext();
	cur->SetNext(tmp2);
	if (tmp2) {
		tmp2->SetPrev(cur);
	}
	delete tmp;
	length --;
	return true;
}

template <class T>
bool List<T>::set(int pos, const T & item) {
	if (pos < 0 || pos >= length) return false;
	int count = 0;
	Node<T>* cur = linked_list->GetHead();
	while (count < pos) {
		cur = cur->GetNext();
		count ++;
	}
	cur->SetVal(item);
	return true;
}

template <class T>
T & List<T>::get(int pos) const {
	if (pos < 0 || pos >= length) {
		cout << "Invalid range!";
		exit(1);
	}
	int count = 0;
	Node<T>* cur = linked_list->GetHead();
	while (count < pos) {
		cur = cur->GetNext();
		count ++;
	}
	return cur->GetVal();
}

template <class T>
int List<T>::getLength() const {
  return this->length;
}
