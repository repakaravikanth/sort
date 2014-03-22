
#ifndef _Sort_
#define _Sort_

template <typename ItemType>
class Sort
{
protected:
    ItemType *array;
  int size;
public:

  Sort(int size);
  void readData();
  virtual void sort()=0;
  void printData();
  bool compare(ItemType,ItemType);
};

#include "Sort.cpp"
#endif
