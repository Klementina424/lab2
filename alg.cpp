#include "alg.h"
#include <iostream>


int BinarySearch(int* A, int size, int search_num)
{
	if (size <= 0)
		throw "Incorrect data";
	if (!(correct(A, size)))
		throw "Array is not sorted";
	int middle, left, right;
	left = 0; right = size - 1;
	while (true)
	{
		if (left > right) return (-1); 
		middle = left + (right - left) / 2;
		if (A[middle] < search_num) left = middle + 1;
		if (A[middle] > search_num) right = middle - 1;
		if (A[middle] == search_num) return middle;
	}
}


void change(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void PrintArray(int* A, int size)
{
	if (size <= 0)
		throw "Incorrect data";
	for (int i = 0; i < size; i++)
	{
		std::cout << A[i] << ' ';
	}
	std::cout << std::endl;
}


void PrintArray(char* A, int size)
{
	if (size <= 0)
		throw "Incorrect data";
	for (int i = 0; i < size; i++)
	{
		std::cout << A[i] << ' ';
	}
	std::cout << std::endl;
}


void BubbleSort(int* A, int size)
{
	if (size <= 0)
		throw "Incorrect data";
	bool control = true;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				if (control == true)
					control = false;
				change(A[j], A[j + 1]);
			}
		}
		if (control == true) break;
	}
}


void QuickSort(int* A, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = A[high];


	while (i <= j)
	{
		while (A[i] < pivot)
			i++;
		while (A[j] > pivot)
			j--;
		if (i <= j)
		{
			change(A[i], A[j]);
			i++;
			j--;
		}
	}
	if (j > low)
		QuickSort(A, low, j);
	if (i < high)
		QuickSort(A, i, high);
}


void BogoSort(int* A, int size)
{
	if (size <= 0)
		throw "Incorrect data";
	while (!correct(A, size))
	{
		for (int i = 0; i < size; ++i)
			change(A[i], A[(rand() % size)]);
	}
}


bool correct(int* A, int size)
{
	if (size <= 0)
		throw "Incorrect data";
	while (--size > 0)
		if (A[size - 1] > A[size])
			return false;
	return true;
}


void CountingSort(char* A, int size)
{
	if (size <= 0)
		throw "Incorrect data";
	char max = char(0);
	for (int i = 0; i < size; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}
	int count_size = int(max + 1);
	int* count = new int[count_size];
	std::memset(count, 0, count_size * sizeof(*count));


	for (int i = 0; i < size; i++)
	{
		if (A[i] != '\0')
		{
			count[int(A[i])]++;
		}
	}

	int i = 0, control = 0;
	for (int j = 0; j < count_size; j++)
	{
		if (count[j] != 0)
		{
			while (i < count[j] + control)
			{
				A[i] = char(j);
				i++;
			}
			control = i;
		}
	}

	delete[]count;
}