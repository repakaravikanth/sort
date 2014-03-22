#ifndef _MergeSort_
#define _MergeSort_

#include "Sort.h"

template <typename ItemType>
class MergeSort:public Sort<ItemType>
{
	public:
		MergeSort(int size);
		virtual void sort();
		int split(ItemType*,int);
		void merge(ItemType*,ItemType*,ItemType*,int);
};

#include "MergeSort.cpp"
#endif