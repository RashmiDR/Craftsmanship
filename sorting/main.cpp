#include <iostream>
#include "sorting.h"
using namespace std;

int main()
{
	
	int size, sorting_type;
	Sort sort;
	
	//Get input array
	cout << "Enter array size to be sorted" << endl;
	cin >> size;
	
	int* array = new int[size];
	
	cout << "Enter the array elements" << endl;
	for(int  i = 0; i<size; i++)
	{
		cin >> array[i];		
	}
	
	cout << "Enter the type of sorting" << endl;
	cout << "1 for Bubble sort" << endl;
	cout << "2 for Selection sort" << endl;
	cout << "3 for Insertion sort" << endl;
	cout << "4 for Shell sort" << endl;
	cout << "5 for Merge sort" << endl;
	cout << "6 for Quick sort" << endl;
	
	cin >> sorting_type;
	
	switch(sorting_type)
	{
		case 1:	sort.BubbleSort(array, size);
				break;
		
		case 2: sort.SelectionSort(array, size);
				break;
				
		case 3: sort.InsertionSort(array, size);
				break;
				
		case 4: sort.ShellSort(array, size);
				break;
		
		case 5: sort.MergeSort(array,size);
				break;
				
		case 6: sort.QuickSort(array, size);
				break;

				
	}
	
	//sort.BubbleSort(array, size);
	//sort.SelectionSort(array, size);
	//sort.InsertionSort(array, size);
	//sort.ShellSort(array, size);
	//sort.MergeSort(array,size);
	//sort.QuickSort(array, size);
	delete[] array;
	
	return 1;
}