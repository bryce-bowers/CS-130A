template <class T>
Iterator<T>::Iterator(DoublyLinkedList<T>* list)
{
  this.pointer = list.GetHead();
  index = 0;
}

template <class T>
Iterator<T>::~Iterator()
{
  delete this.pointer;
}

template <class T>
void Iterator<T>::operator=(int val)
{
  if (val < 0) return; //Does not check if above the upper bound
  int difference = val - index;
  if (difference > 0)
    {
      for (int i = 0; i < difference; i++)
	{
	  this.pointer->GetNext();
	  index++;
	}
    }
  else if (difference < 0)
    {
      for (int i = 0; i > difference; i--)
	{
	  this.pointer->GetPrev();
	  index--;
	}
    }
  return;
}

template <class T>
void Iterator<T>::operator+(int val)
{
  if (val < 0)
    {
      val *= -1;
      operator-(val); //I highly doubt this is correct
      return;
    }
  for (int i = 0; i < val; i++)
    {
      this.pointer->GetNext();
      index++;
    }
  return;
}

template <class T>
void Iterator<T>::operator-(int val)
{
  if (val < 0)
    {
      val *= -1;
      operator+(val); //I highly doubt this is correct
      return;
    }
  for (int i = 0; i < val; i++)
    {
      this.pointer->GetPrev();
      index--;
    }
  return;
}

template <class T>
bool Iterator<T>::operator!=(int val)
{
  if (index != val)
    return true;
  return false;
}

template <class T>
bool Iterator<T>::operator==(int val)
{
  if (index == val)
    return true;
  return false;
}

template <class T>
bool Iterator<T>::operator<(int val)
{
  if (index < val)
    return true;
  return false;
}

template <class T>
bool Iterator<T>::operator<=(int val)
{
  if (index <= val)
    return true;
  return false;
}

template <class T>
bool Iterator<T>::operator>(int val)
{
  if (index > val)
    return true;
  return false;
}

template <class T>
bool Iterator<T>::operator>=(int val)
{
  if (index >= val)
    return true;
  return false;
}

template <class T>
void Iterator<T>::operator++()
{
  this.pointer->GetNext();
  index++;
}

template <class T>
void Iterator<T>::operator--()
{
  this.pointer->GetPrev();
  index--;
}
