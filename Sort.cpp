#include <iostream>
#include <string>
#include <limits>
using namespace std;

template <typename ItemType>
Sort<ItemType>::Sort(int size)
{
  this->size = size;
  array = new ItemType[size];
}

template <typename ItemType>
void Sort<ItemType>::readData()
{
  cout<<"Enter Data\n";
  for(int i=0; i<size; i++)
  {
    while(!(cin >> array[i]))
    {
      cout<<"Please enter valid data\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
}

template <typename ItemType>
void Sort<ItemType>::printData()
{
  for(int i=0; i<size; i++)
    cout<<array[i]<<"\t";
  cout<<endl;
}

template <typename ItemType>
bool Sort<ItemType>::compare(ItemType a,ItemType b)
{
  return ((a>b)?1:0);
}

//Same function and specific to strings.
template <>
bool Sort<string>::compare(string a,string b)
{
  return ((a.compare(b)>0)?1:0);
}