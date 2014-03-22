template <typename ItemType>
SelectionSort<ItemType> :: SelectionSort(int size) : Sort<ItemType>(size)
{

}

template <typename ItemType>
void SelectionSort<ItemType>::sort()
{
	int minIndex;
	ItemType temp;

	for(int i=0; i<this->size; i++)
	{
		minIndex =  i;
		for(int j=i+1; j<this->size; j++)
		{
			if(this->array[minIndex] > this->array[j])
			{
				minIndex = j;
			}
		}
		if(i != minIndex)
		{
			temp = this->array[i];
			this->array[i] = this->array[minIndex];
			this->array[minIndex] = temp;
		}
	}
}