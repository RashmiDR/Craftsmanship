#include "sorting.h"

Sort::Sort()
{

}

Sort::~Sort()
{

}

bool Sort::isSorted(int* array, int size)
{
	if(array == NULL)
	{
		cout << "Invalid array\n";
		return false;	
	}
	for(int i = 0; i< size -1; i++)
	{
		if(array[i] > array[i+1])
		{
			return false;
		}
	}
	return true;	
}

bool Sort::test(int* array, int size, string sortingMethod)
{

	if(isSorted(array, size))
	{
		cout << sortingMethod << " works great" << endl;
		return true;	
	}
	else
	{
		cout << sortingMethod << " failed"<< endl; 
		return false;	
	}
}




void Sort::printArray(int* array, int size)
{
	for(int i = 0; i<size; i++)
	{
		cout << "\t" << array[i];
	}
	cout << endl;
}

void Sort::swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


/*Iterate through the array comparing 2 adjacent elements*/
void Sort::BubbleSort(int* array, int size)
{
	cout << "\nBubble sort" << endl;
	int i=0, j=0;
	for(i = 0; i<size; i++)
	{
		for(j=0; j<size-1; j++) //size -1 as an item is compared with its next element
		{
			
			if(array[j] > array[j+1])
			{
				swap(&array[j], &array[j+1]);				
			}			
		}
		
		cout << "After pass " << i << endl;
		printArray(array, size);
	}
	
	test(array, size, "Bubble Sort");
}


/*find the lowest and swap with the first element in the array,
find the second lowest and swap it with the second element in the array

Signature properties:
1. Running time is insensitive to input: Takes the same time even when the input array is already sorted.
2. Data movement is minimal:Each of the N exchanges changes the value of two array entries, 
so selection sort uses N exchanges—the number of array accesses is a linear function of the array size. 
None of the other sorting algorithms have this property (most involve linearithmic or quadratic growth).
*/
void Sort::SelectionSort(int* array, int size)
{	
	for(int i=0; i<size; i++)
	{
		int minIndex = i;
		for(int j= i+1; j<size; j++)
		{
			if(array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		swap(&array[i], &array[minIndex]);
		cout << "After pass " << i << endl;
		printArray(array, size);
	}		
	test(array, size, "Selection Sort");
}


/*compare each of the element with the elements before it in the array,
insert at the correct position

Insertion sort is an excellent method for partially sorted arrays and for tiny arrays. 
*/

void Sort::InsertionSort(int* array, int size)
{
	int i=0, j=0;
	for(i = 1; i<size; i ++)
	{
		int currentElement = array[i];
		for(j = i-1; j>=0 && array[j] > currentElement; j--)
		{
			//Move the greater array elements down
			array[j+1] = array[j];
		}
		array[j+1] = currentElement;
		
		cout << "After pass " << i << endl;
		printArray(array, size);
	}
	test(array, size, "Insertion Sort");
}



//Shell sort is insertion sort applied to subsequences at a distance d
void Sort::ShellSort(int* array, int size)
{
	int i=0, j=0, d =0;
	
	d = size;
	
	while(d>1)
	{
		d = (d+1)/2; // decide the distance or the h-factor
		for(i = d; i < size; i++) //start at the distance till the end of the array
		{
			for(j = i; j>=d && array[j] < array[j-d]; j-=d)//compare it back with the element at distance of d, 
											//continue doing it at the same distance till the smallest element 
											//at that distance gets to top(front) of the array
			{

				swap(&array[j], &array[j-d]);		
	
			}
		}
		cout << "After pass " << d << endl;
		printArray(array, size);
	}
	test(array, size, "Shell Sort");
}


//Merge sort
//Merge sort is guaranteed O(nlog(n)) sort . 
//Like heap sort, merge sort requires additional memory proportional 
//to the size of the input for scratch space, but, unlike heap sort, 
//merge sort is stable, meaning that "equal" elements are ordered the same once sorting is complete. 

void Sort::MergeSort(int* array, int size)
{
	merge_sort(array, 0, size-1);	
	test(array, size, "Merge Sort");
}

void Sort::merge_sort(int *array, int begin, int end)
{
	if(begin < end)
	{
		int mid = (begin+end)/2;	
		merge_sort(array, begin, mid);
		merge_sort(array, mid+1, end);
		merge(array, begin, end);
	}
}

void Sort::merge(int *array, int begin, int end)
{
	int i,j,k;
	int size = end - begin + 1;
	int temp[size];
	int mid = (begin+end)/2;
	
	i = begin;
	j = mid+1;
	k = 0;
	
	while(i <= mid && j <= end)
	{
		if(array[i] < array[j])	
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	} 
	//copy the elements left over in the sub-arrays
	while(i <= mid)
	{
		temp[k++] = array[i++];
	}
	while(j <= end)
	{
		temp[k++] = array[j++];
	}
	
	//copy back the merged array to the original array
	for(i = begin; i <= end; i++)
	{
		array[i] = temp[i-begin];
	}
	
	cout << "After merging from " << begin << " to " << end << ":" << endl;
	printArray(array, size);
	
}


//Quick sort
void Sort::QuickSort(int * array, int size)
{
	quick_sort(array, 0, size-1);
	printArray(&array[0], size);
	test(array, size, "Quick Sort");
}

void Sort::quick_sort(int *array, int left, int right)
{
	int i = left, j=right;
	int pivot = array[(left+right)/2];
	int tmp;	
	
	while(i<=j)
	{
		while(array[i] < pivot)
			i++;
		while(array[j] > pivot)
			j--;
		if(i<=j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;	
			i++;
			j--;
		}
	}
		
	//recursive
	if(left < j)
		quick_sort(array, left, j);
	
	if(i < right)
		quick_sort(array, i, right);
		
	cout << "quick sort from " << left << " to " << right << " with " << pivot << " as pivot" << endl;
	printArray(&array[left], right-left+1);
	
}


//Heap sort









