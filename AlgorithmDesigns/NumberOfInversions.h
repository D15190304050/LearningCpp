#pragma once
#include "stdafx.h"

namespace AlgorithmDesigns
{
	// The NumberOfInversions class represents a static method set that provide several solutions to deal with the
	// number of inversions problems.
	class NumberOfInversions
	{
	private:
		// Stably merge array[low ... middle] with array[middle+1 ... high] using auxiliary[low ... high].
		// T : A generic type that is Comparable.
		// data : An int array.
		// auxiliary : An auxiliary array.
		// low : The lower limit of this merge operation.
		// high : The upper limit of this merge operation.
		// Returns : The number of inversions in sub-array[low ... high].
		template<class T>
		static int MergeArray(T data[], T auxiliary[], int low, int middle, int high)
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

			// Return the number of inversions computed here.
			return count;
		}

		// Merge sort array[low ... high] using auxiliary array.
		// T : A generic type that is Comparable.
		// data : An int array.
		// auxiliary : An auxiliary array.
		// low : The lower limit of this merge operation.
		// high : The upper limit of this merge operation.
		// count : The counter that computes the number of inversions.
		template<class T>
		static void MergeSort(T data[], T auxiliary[], int low, int high, int * count)
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

		// The NumberOfInversions class shouldn't be instantiated.
		NumberOfInversions() {}

	public:
		// Solves the number of inversions problem using merge sort.
		// T : A generic type that is Comparable.
		// data : An int array.
		// length : The length of the input array.
		// Returns : The number of inversions of the specified array.
		template<class T>
		static int MergeBasedCount(T data[], T length)
		{
			// Initialize the counter to 0.
			int count = 0;

			// Initialize the auxiliary array for merge sort.
			int * auxiliary = new int[length];

			// Merge sort the array using the auxiliary and count the number of inversions.
			MergeSort(data, auxiliary, 0, length - 1, &count);

			// Release the memory of the auxiliary array.
			delete[] auxiliary;

			// Return the number of inversions.
			return count;
		}
	};
}