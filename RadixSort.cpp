template <typename ItemType>
RadixSort<ItemType>::RadixSort(int size) : Sort<ItemType>(size)
{
	for(int i=0; i<26; i++)
	{
		lists.push_back(new LinkedList<ItemType>());
	}
}

RadixSort<int>::RadixSort(int size) : Sort<int>(size)
{
	//Create vector of 10 linked lists. As we have 10 digits (0-9), vector will have 10 linked lists. i.e Each digit will have linkedlist
	for(int i=0; i<10; i++)
	{
		lists.push_back(new LinkedList<int>());
	}
}
/*
template<>
void RadixSort<char>::sort()
{
}

template<>
void RadixSort<string>::sort()
{
}*/

template <typename ItemType>
void RadixSort<ItemType>::sort()
{
	
}

template <>
void RadixSort<string>::sort()
{
	int maxStringLength = calcualteMaxStringLength();
	char ch;
	int i=0;
	do
	{
		for(; i<this->size; i++)
		{
			if(this->array[i].length()-i >= 0 )
			{
				ch = this->array[i][this->array[i].length()-i];
				tolower(ch);
				lists[ch-96]->addItem(this->array[i]);
			}
			else
				lists[0]->addItem(this->array[i]);
		}

		//Printing linked lists
		cout<<"\nPrinting LinkedLists\n";
		for(int i=0;i<(int)lists.size();i++)
		{
			cout<<"["<<i<<"]--> ";
		 	lists[i]->print();
		}

		//Retrive all values from lists start from 0th linkedList and store them in array
		for(int i=0,j=0; i<this->size; i++)
		{
			//Don't get values from linkedlist if the linkedlist is empty. So skip those lists.
			while(lists[j]->getItemCount()==0)
				j++;
			//Once non-empty set is identified get values from the list and store them in array
			this->array[i] = lists[j]->pop();		
		}

	}while(++i < maxStringLength);
}


//template<>
void RadixSort<int>::sort()
{
	int m=1;
	int div,rem;
	
	int maxDigitCount;
	//calcualte max digit count
	maxDigitCount = calculateMaxNoOfDigits();
	cout<<"maxDigitCount "<<maxDigitCount<<endl;
	do
	{
		for(int i=0; i<this->size; i++)
			cout<<this->array[i]<<" ";
		 cout<<endl;
		//Store array value based on remainder of array value.
		for(int i=0; i<this->size; i++)
		{
			div = this->array[i]/m;
			rem = div % 10;
			lists[rem]->addItem(this->array[i]);
		}

		//Printing linked lists
		cout<<"\nPrinting LinkedLists\n";
		for(int i=0;i<(int)lists.size();i++)
		{
			cout<<"["<<i<<"]--> ";
		 	lists[i]->print();
		}

		//Retrive all values from lists start from 0th linkedList and store them in array
		for(int i=0,j=0; i<this->size; i++)
		{
			//Don't get values from linkedlist if the linkedlist is empty. So skip those lists.
			while(lists[j]->getItemCount()==0)
				j++;
			//Once non-empty set is identified get values from the list and store them in array
			this->array[i] = lists[j]->pop();		
		}
		
		m *= 10;
		
	}while(--maxDigitCount>0);
}

template <typename ItemType>
int RadixSort<ItemType>::calcualteMaxStringLength()
{
	return 0;
}

template <>
int RadixSort<string>::calcualteMaxStringLength()
{
	int maxLength=0;
	for(int i=0; i<this->size; i++)
	{
		if(maxLength<this->array[i].length() )
			maxLength = this->array[i].length();
	}
	return maxLength;
}

int RadixSort<int>::calculateMaxNoOfDigits()
{
	int digitCount,temp,maxDigitCount=0;
	for(int i=0; i<this->size; i++)
	{
		temp = this->array[i];
		digitCount=0;
		do
		{
			temp /= 10;
			digitCount++;
		}while(temp!=0);
		if(maxDigitCount < digitCount)
			maxDigitCount = digitCount;
	}
	cout<<" In maxDigitCount function "<<maxDigitCount<<endl;
	return maxDigitCount;
}
