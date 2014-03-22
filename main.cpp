#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include <iostream>
#include <limits>
using namespace std;

template <typename ItemType>
void doSort(Sort<ItemType> *sortObj);

int main()
{
  int datatypeChoice,size,sortType;
  string selectedSort;
  char runAgain;
  cout<<"\n\n***********************************************************************************************\n";
  cout<<"\t\t\t\t\tWELCOME TO SORT PROJECT\n";
  cout<<"***********************************************************************************************\n\n";
  
  do
  {
    cout<<"This Project supports following sort algorithms:\n";
    cout<<"\t\t 1.BubbleSort\n";
    cout<<"\t\t 2.MergeSort\n";
    cout<<"\t\t 3.QuickSort\n";
    cout<<"\t\t 4.SelectionSort\n";
    cout<<"\t\t 5.InsertionSort\n";
    cout<<"\nPlease select one sort algorithm: ";
    while(!(cin>>sortType) || !(sortType>=1 && sortType<=5))
    {
      cout<<"Please enter valid number from 1 to 5\n";
      cin.clear();     //The cin.clear() clears the error flag on cin (so that future I/O operations will work correctly)
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // input which failed will be sitting in buffer, so we need to clear the buffer. 
    }
    switch(sortType)
    {
      case 1: selectedSort="BubbleSort"; break;
      case 2: selectedSort="MergeSort"; break;
      case 3: selectedSort="QuickSort"; break;
      case 4: selectedSort="SelectionSort"; break;
      case 5: selectedSort="InsertionSort"; break;
    }
    cout<<"\nWhich datatype values do you want to enter?:\n";
    cout<<"1.Integers \n2.Characters \n3.Strings\n\n";
    cout<<"Enter your choice for datatype: ";
    while(!(cin>>datatypeChoice) || !(datatypeChoice>=1 && datatypeChoice<=3))
    {
      cout<<"Please enter valid input type && number between 1 and 4\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"\nHow many values do want to sort?: ";
    while(!(cin>>size) || size<0 )
    {
      cout<<"Please enter integer value && should be greater than zero\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"------------------------------------------------------------------------------------------------\n\n";
    cout<<"You chose to enter "<<size;
    (datatypeChoice==1) ? cout<<" Integer(s) " : ((datatypeChoice==2) ? cout<<" Character(s) " : cout<<" String(s)");
    cout<<"to sort using "<<selectedSort<<", So Please ";
    //Create objects based on the input datatypeChoice



    if(datatypeChoice ==1)
    {
      Sort<int> *sortObj; 
      switch (sortType)
      {
        case 1:
                sortObj = new BubbleSort<int>(size);
                break;
        case 2:
                sortObj = new MergeSort<int>(size);
                break;
        case 3:
               sortObj = new QuickSort<int>(size);
                break; 
        case 4:
               sortObj = new SelectionSort<int>(size);
                break; 
        case 5:
               sortObj = new InsertionSort<int>(size);
                break; 
      }
      doSort(sortObj);
    }
    else if(datatypeChoice ==2)
    {
      Sort<char> *sortObj; 
      switch (sortType)
      {
        case 1:
                sortObj = new BubbleSort<char>(size);
                break;
        case 2:
                sortObj = new MergeSort<char>(size);
                break;
        case 3:
               sortObj = new QuickSort<char>(size);
                break; 
        case 4:
               sortObj = new SelectionSort<char>(size);
                break; 
        case 5:
               sortObj = new InsertionSort<char>(size);
                break; 
      }
      doSort(sortObj);
    }
    else
    {
      Sort<string> *sortObj; 
      switch (sortType)
      {
        case 1:
                sortObj = new BubbleSort<string>(size);
                break;
        case 2:
                sortObj = new MergeSort<string>(size);
                break;
        case 3:
               sortObj = new QuickSort<string>(size);
                break; 
        case 4:
               sortObj = new SelectionSort<string>(size);
                break; 
        case 5:
               sortObj = new InsertionSort<string>(size);
                break; 
      }
      doSort(sortObj);
    }
    cout<<"\nDo you want to do again [y/n]: ";
    
    while( !(cin>>runAgain) || !(runAgain=='y' || runAgain=='Y' || runAgain=='n' || runAgain=='N'))
    {
      cout<<"Please enter valid choice. It should be [y/n]\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    if(runAgain == 'y' || runAgain == 'Y')
      cout<<"\n\n************************************************************************************************\n\n";
  }while(runAgain == 'Y' || runAgain == 'y');  
  cout<<"\n\n****************************************GOOD BYE*************************************************\n\n";
}

template <typename ItemType>
void doSort(Sort<ItemType> *sortObj)
{
  sortObj -> readData();
  cout<<"\nBefore sorting the data is\n";
  sortObj -> printData();
  sortObj -> sort();
  cout<<"\nAfter sorting the data is\n";
  sortObj -> printData();
}


