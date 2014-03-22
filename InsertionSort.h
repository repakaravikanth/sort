#ifndef _InsertionSort
#define _InsertionSort

#include "Sort.h"

template<typename ItemType>
class InsertionSort:public Sort<ItemType>
{
	public:
		InsertionSort(int);
		void sort();
};

#include "InsertionSort.cpp"
#endif