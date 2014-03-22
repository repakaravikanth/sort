#ifndef _QuickSort_
#define _QuickSort_

#include <cstdlib>
#include "Sort.h"

template <typename ItemType>
class QuickSort : public Sort<ItemType>
{
	public:
		QuickSort(int);
		virtual void sort();
		int sortWithPivot(int,int);
};

#include "QuickSort.cpp"
#endif