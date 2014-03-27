#ifndef _RadixSort
#define _RadixSort

#include "Sort.h"
#include "LinkedList.h"

#include <vector>
using namespace std;


template <typename ItemType>
class RadixSort: public Sort<ItemType>
{
 	vector<LinkedList<ItemType>*> lists;

	public:
		RadixSort(int);
		void sort();
		int calcualteMaxStringLength();
};


template <>
class RadixSort<int>: public Sort<int>
{
 	vector<LinkedList<int>*> lists;

	public:
		RadixSort(int);
		void sort();
		int calculateMaxNoOfDigits();
};

#include "RadixSort.cpp"
#endif