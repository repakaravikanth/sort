template <typename ItemType>
RadixSort<ItemType>::RadixSort(int size) : Sort<ItemType>(size)
{
	for(int i=0; i<26; i++)
	{
		lists.push_back(new LinkedList<ItemType>());
	}
}

template<>
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
	//calculateMaxNoOfDigits();
	char ch;
	//store each character in lists based on char value.
	for(int i=0; i<this->size; i++)
	{
		ch = this->array[i];
		ch = tolower(ch);
		lists[ch-97]->addItem(this->array[i]);
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
}

template <>
void RadixSort<string>::sort()
{
	//int maxStringLength = calculateMaxStringLength();

	int maxStringLength=0;
	for(int i=0; i<this->size; i++)
	{
		if(maxStringLength<(int)this->array[i].length() )
			maxStringLength = this->array[i].length();
	}

	cout<<"maxStringLength "<<maxStringLength<<endl;
	char ch;
	int iterator=0;
	do
	{
		for(int i=0; i<this->size; i++)
		{
			//Check if string has still more charcters to be read. 
			//For the first time we should compare strings with last character, so length - iterator -1. Next time, iterator will be incremented so that we will get length-2 character.
			if((int)this->array[i].length()-iterator > 0 )
			{
				ch = this->array[i][this->array[i].length()-iterator-1];
				ch = tolower(ch);
				lists[ch-97]->addItem(this->array[i]);				
			}
			//If you read all characters from a string, then store this string again in lists by using first character
			else
			{
				ch = this->array[i][0];
				ch = tolower(ch);
				lists[ch-97]->addItem(this->array[i]);	
			}
		}
		
		//Printing linked lists
		cout<<"\nPrinting LinkedLists\n";
		char temp = 'a';
		for(int i=0;i<(int)lists.size();i++)
		{
			cout<<"["<<temp++<<"]--> ";
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
		
	}while(++iterator < maxStringLength);
}


template<>
void RadixSort<int>::sort()
{
	int m=1;
	int div,rem;
	//this->calculateMaxNoOfDigits();
	int maxDigitCount;
	//calcualte max digit count
	maxDigitCount = 5;//calculateMaxNoOfDigits();
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
/*
template<typename ItemType>
int RadixSort<ItemType>::calculateMaxNoOfDigits()
{
	return 0;
}
*/
//Calculate digit count by dividing the value by zero until unless you get a zero.
template<>
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
	return maxDigitCount;
}
