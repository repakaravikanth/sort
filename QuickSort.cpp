
template <typename ItemType>
QuickSort<ItemType>::QuickSort(int size):Sort<ItemType>(size)
{

}

template<typename ItemType>
void QuickSort<ItemType>::sort()
{
	int left=0, right = this->size-1;
	sortWithPivot(left,right);
}

/*
Quicksort will have pivot. Select one pivot (usually middle value). 
Do the mechanism suchthat all values before pivot should be below the pivot and all values above the pivot should be greater than pivot. 
Divide the array into two subarrays based on pivot and repeat the same procedure agaion.

*/
template<typename ItemType>
int QuickSort<ItemType>::sortWithPivot(int left,int right)
{
	int pivot,nextPivot,max,min;
	ItemType temp;

	if(left >= right)
		return 0;

	pivot = (right + left) /2;
	nextPivot = pivot;
	max = right;
	min = left;

	for(int i=left;i<right;i++)
	{
		while((this->array[left] < this->array[pivot]) && left <= pivot)
			left++;
		while((this->array[right] > this->array[pivot]) && right >= pivot)
			right--;
		if(left != right && (this->array[left] > this->array[right]))
		{
			if(left == pivot)
				nextPivot = right;
			else if(right == pivot)
				nextPivot = left;
			temp = this->array[right];
			this->array[right] = this->array[left];
			this->array[left] = temp;
		}
	}
	sortWithPivot(min,nextPivot-1);
	if(nextPivot+1 < max)
		sortWithPivot(nextPivot,max);
	return 1;
}