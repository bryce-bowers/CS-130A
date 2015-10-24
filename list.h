#ifndef LIST_H
#define LIST_H
#include "doubly_linked_list.h"

template <class T>
class List {
private:
	DoublyLinkedList<T>* linked_list;
	int length;	
public:
	List();
	~List();

	bool insert(int pos, T & item);
	bool remove(int pos);
	bool set(int pos, T & item);
	T & get(int pos);
};
#include "list.cpp"
#endif
