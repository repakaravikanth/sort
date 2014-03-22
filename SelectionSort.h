#ifndef _SelectionSort
#define _SelectionSort

#include "Sort.h"

template<typename ItemType>
class SelectionSort : public Sort<ItemType>
{
public:
	SelectionSort(int);
	~SelectionSort();
	void sort();
};

#include "SelectionSort.cpp"

#endif