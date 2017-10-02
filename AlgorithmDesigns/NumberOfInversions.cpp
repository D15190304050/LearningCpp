#pragma once
#include "stdafx.h"
#include "NumberOfInversions.h"

namespace AlgorithmDesigns
{
	int NumberOfInversions::MergeArray(int data[], int auxiliary[], int low, int middle, int high)
	{
		// Initialize counter to 0.
		int count = 0;

		// Copy original array to auxiliary array.
		for (int i = low; i <= high; i++)
			auxiliary[i] = data[i];

		// Scanner of sub-array[low ... middle].
		int left = low;

		// Scanner of sub-array[middle+1 ... high].
		int right = middle + 1;

		// Merge back to data.
		for (int i = low; i <= high; i++)
		{
			if (left > middle)
				data[i] = auxiliary[right++];
			else if (right > high)
				data[i] = auxiliary[left++];
			else if (auxiliary[right] < auxiliary[left])
			{
				count += middle - left + 1;
				data[i] = auxiliary[right++];
			}
			else
				data[i] = auxiliary[left++];
		}

		return count;
	}

	void NumberOfInversions::MergeSort(int data[], int auxiliary[], int low, int high, int * count)
	{
		// Returns if there is 1 or 0 element in the array.
		if (high <= low)
			return;

		// Get the middle index of the range to merge.
		int middle = (low + high) / 2;

		// Merge sort the left half.
		MergeSort(data, auxiliary, low, middle, count);

		// Merge sort the right half.
		MergeSort(data, auxiliary, middle + 1, high, count);

		// Merge results and update the counter.
		*count += MergeArray(data, auxiliary, low, middle, high);
	}

	int NumberOfInversions::MergeBasedCount(int data[], int length)
	{
		int count = 0;

		int * auxiliary = new int[length];

		MergeSort(data, auxiliary, 0, length - 1, &count);

		delete[] auxiliary;

		return count;
	}
}