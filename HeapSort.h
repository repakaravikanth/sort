#ifndef _HeapSort
#define _HeapSort

#include "Sort.h"

template <typename ItemType>
class  HeapSort : public Sort<ItemType>
{
public:
	 HeapSort(int);
	 virtual void sort();
	 void constructHeap();
	 void swapRootWithLeaf(int);
	 void reConstructHeap(int);
};

#include "HeapSort.cpp"
#endif