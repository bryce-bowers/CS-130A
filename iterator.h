#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
class Iterator
{
 private:
  int index;
  Node<T>* pointer = new Node<T>;
 public:
  Iterator(DoublyLinkedList)* list);
  ~Iterator();

  void operator+(int val);
  void operator-(int val);
  void operator++();
  void operator--();
  bool operator<(int val);
  bool operator<=(int val);
  bool operator>(int val);
  bool operator>=(int val);
  bool operator==(int val);
  bool operator!=(int val);
  void operator=(int val);
};
#endif

#include "iterator.cpp"
