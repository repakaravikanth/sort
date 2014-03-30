
template<typename ItemType>
HeapSort<ItemType>::HeapSort(int size):Sort<ItemType>(size)
{

}


/*This sort has 3 steps

1) Build heap from the given data. Max heap will be created that is maximum element will be root element.
2) Swap root element (maximum element) with last element in array.
3) Reconsturct heap except the last element.
4) Repeat the process 2 and 3 until heap is empty 

*/
template<typename ItemType>
void HeapSort<ItemType>::sort()
{
	int max = this->size;

	//step 1
	constructHeap();

	while(max-- > 0)
	{	
		swapRootWithLeaf(max);		//step 2
		reConstructHeap(max);		//step 3
	}
}

/*
In construction of max heap, check each item in array with its parent if the child is higher value then swap parent value with child,
 continue this process until you reach root node of the heap. This whole process should be repeated for each node in array starting from 2nd element in array.

For a given index i, it's childern are 2*i+1, 2*i+2

For a given index i, it's parent calcuation  is like
	if i is even then i/2 - 1
	if i is odd then i/2
*/

template<typename ItemType>
void HeapSort<ItemType>::constructHeap()
{
	ItemType temp;
	int parentIndex, currentIndex;
	
	for(int i=1; i<this->size; i++)
	{
		currentIndex = i;
		//calculate parent index of currentIndex
		parentIndex = currentIndex%2 == 0 ? currentIndex/2-1 : currentIndex/2;
		
		//Do the loop until it reaches root of the heap
		while(parentIndex >= 0)
		{
			//Check if child value is greater than parent value swap elements
			if(this->array[currentIndex] > this->array[parentIndex] )
			{
				temp = this->array[currentIndex];
				this->array[currentIndex] = this->array[parentIndex];
				this->array[parentIndex] = temp;

				//update currentIndex to its parentIndex and recalculate parentIndex again.
				currentIndex = parentIndex;
				parentIndex = currentIndex%2 == 0 ? currentIndex/2-1 : currentIndex/2;				
			}
			//If child value is not greater than exit the loop because heap is already constructed upto it's parent node. So no need of check again.
			else
				break;
		}
	}
	
	/*cout<<"After tree construction\n";
	for(int i=0; i<this->size; i++)
		cout<<this->array[i]<<" ";
	cout<<endl;*/
}

/*
	After tree is constructed swap the root element with right most leaf.
*/
template<typename ItemType>
void HeapSort<ItemType>::swapRootWithLeaf(int leaf)
{
	ItemType temp;
	temp = this->array[0];
	this->array[0] = this->array[leaf];
	this->array[leaf] = temp;
	/*
	cout<<"leaf "<<leaf<<endl;
	for(int i=0; i<this->size; i++)
		cout<<this->array[i]<<" ";
	cout<<endl;*/
}

/*
After swaping of root element with right most leaf, we need to reconstruct the heap again. 

This function will take max index as input parameter. max index is (array size) - (number of elements already sorted)

Reconstruction alogirthm is like:

1) Start with root node
2) calculate the maximum value of its both children. 
3) Compare that maximum value with parent node. [Initially parent node is root of the heap tree]
4) If child value is greater than parent then swap the elements and then recalcluate new parent and children indexs. 
5) Else break because rest of the tree is already in heap tree order
6) Continue this procedure until right child reaches maximum index
7) If child2 == max, then compare only parent node with it's left child and do the swapping if necessary.
*/

template<typename ItemType>
void HeapSort<ItemType>::reConstructHeap(int max)
{
	int currentIndex =0, index;
	int child1=1,child2=2;
	ItemType temp;

	//Do loop until child2 reaches max
	while(child2 < max)
	{
		//Calculate index value of child which has higher value
		index = this->array[child1] > this->array[child2] ? child1 : child2;
		//Do the swapping with parent if necessary
		if(this->array[index] > this->array[currentIndex] )
		{	
			temp = this->array[index];
			this->array[index] = this->array[currentIndex];
			this->array[currentIndex] = temp;		

			currentIndex = index;
			child1 = 2*currentIndex + 1;
			child2 = 2*currentIndex + 2;
		}
		else
			break;		
	}

	//If child2 reaches maximum element then we should not compare parent node with child2 beacuse child2 is not in the heap.
	//In this case we should compare child1 with parent because child1 may have higher value than parent. So do the swapping if necessary.
	if(child2 == max)
	{
		if(this->array[child1] > this->array[currentIndex] )
		{	
			temp = this->array[currentIndex];
			this->array[currentIndex] = this->array[child1];
			this->array[child1] = temp;		
		}
	}
	
	/*cout<<"After reconstruction\n";
	for(int i=0; i<this->size; i++)
		cout<<this->array[i]<<" ";
	cout<<endl;*/
}
