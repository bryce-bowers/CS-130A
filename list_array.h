#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H
#define MIN_LENGTH 2
#include <stdlib.h>

template <class T>
class ListArray {
private:
	T* list;
	int length; //number of elements
	int cur_size; //current size of array

public:
	ListArray() {
		list = (T*)malloc(MIN_LENGTH  * sizeof(T));
		length = 0;
		cur_size = MIN_LENGTH;
	}
	~ListArray() {
		delete list;
	}	

	bool insert(int pos, const T & item);
	bool remove(int pos);
	bool set(int pos, const T & item);
	T & get(int pos) const;

};
#include "list_array.cpp"
#endif
