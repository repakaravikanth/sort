#ifndef _BubbleSort_
#define _BubbleSort_

#include "Sort.h"

template <typename ItemType>
class BubbleSort : public Sort<ItemType>
{
 public:
  BubbleSort(int size);
  void sort();  
};

#include "BubbleSort.cpp"
#endif
