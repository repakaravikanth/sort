template<typename ItemType>
InsertionSort<ItemType>::InsertionSort(int size) : Sort<ItemType>(size)
{

}

template<typename ItemType>
void InsertionSort<ItemType>::sort()
{
	ItemType temp;
	for(int i=0;i<this->size;i++)
	{
		for(int j=i; j>0; j--)
		{
			if(this->array[j] < this->array[j-1])
			{
				temp = this->array[j];
				this->array[j] = this->array[j-1];
				this->array[j-1] = temp;
			}
			else
				break;
		}
	}
}