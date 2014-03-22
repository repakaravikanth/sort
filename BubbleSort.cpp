template <typename ItemType>
BubbleSort<ItemType>::BubbleSort(int size) : Sort<ItemType>(size)
{
} 

template <typename ItemType>
void BubbleSort<ItemType>::sort()
{
  ItemType temp;
  for(int i=0; i<this->size-1; i++)
  {
    for(int j=0; j< this->size-1-i; j++)
    {
      if(compare(this->array[j],this->array[j+1]))
      {
      	temp = this->array[j];
      	this->array[j] = this->array[j+1];
      	this->array[j+1] = temp;
      }
    }
  }
}
