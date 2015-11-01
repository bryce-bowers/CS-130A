#ifndef LIST_H
#define LIST_H
#include "doubly_linked_list.h"
using namespace std;

template <class T>
class List {
private:
	DoublyLinkedList<T>* linked_list;
	int length;

public:	
	class iterator
        {
            public:
                iterator(T* ptr) : ptr_(ptr) { }
                iterator operator++() { iterator i = *this; ptr_++; return i; }
                iterator operator++(int junk) { ptr_++; return *this; }
                T& operator*() { return *ptr_; }
                T* operator->() { return ptr_; }
                bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }
            private:
                T* ptr_;
        };
	List();
	~List();

	bool insert(int pos, const T & item);
	bool remove(int pos);
	bool set(int pos, const T & item);
	T & get(int pos) const;
	int getLength() const;
};
#include "list.cpp"
#endif
