#include <iostream>

using namespace std;

class Sort
{
private:

	void printArray(int* array, int size);
	void swap(int* x, int* y);
	bool test(int* array, int size, string sortingMethod);
	bool isSorted(int* array, int size);
	void merge_sort(int* array, int begin, int end);
	void merge(int *array, int begin, int end);
	void quick_sort(int *array, int left, int right);

	

public:
	
	Sort();
	~Sort();
	//void CreateInputArray();
	void BubbleSort(int* array, int size);
	void SelectionSort(int* array, int size);
	void InsertionSort(int* array, int size);
	void ShellSort(int* array, int size);
	void MergeSort(int* array, int size);
	void QuickSort(int * array, int size);
};