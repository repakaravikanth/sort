

template <typename ItemType>
MergeSort<ItemType>::MergeSort(int size) : Sort<ItemType>(size)
{}

template <typename ItemType>
void MergeSort<ItemType>::sort()
{
	split(this->array,this->size);
}

template <typename ItemType>
int MergeSort<ItemType>::split(ItemType *array, int size)
{
	if(size<2)
		return 1;		
	int mid = size/2;
	//cout<<"mid value "<<mid<<endl;
	ItemType *leftArray = new ItemType[mid];
	ItemType *rightArray = new ItemType[size-mid];

	for(int i=0; i<size/2; i++)
		leftArray[i] = array[i];
	int j=0;
	for(int i=size/2; i<size; i++)
		rightArray[j++] = array[i];
	split(leftArray,mid);
	split(rightArray,size-mid);
	merge(leftArray,rightArray,array,size);	
	return 1;
}

template <typename ItemType>
void MergeSort<ItemType>::merge(ItemType *leftArray,ItemType * rightArray,ItemType *array,int size)
{
	int mid = size/2;
	int j=0,k=0,i=0;
	while(j<mid && k<size-mid)
	{
		if(leftArray[j] < rightArray[k])
			array[i++] = leftArray[j++];
		else
			array[i++] = rightArray[k++];
	}
	while(j<mid)
		array[i++] = leftArray[j++];
	while(k<mid-size)
		array[i++] = rightArray[k++];
}

