#pragma once
#include "stdafx.h"

namespace FundamentalAlgorithms
{
	namespace Sort
	{
		// The Merge class provides static methods for sorting an array using merge sort.
		class Merge
		{
		private:
			// Merge array[low ... middle] with array[middle+1 ... high].
			// T : A generic type that is Comparable.
			// data : An int array.
			// auxiliary : An auxiliary array.
			// low : The lower limit of this merge operation.
			// high : The upper limit of this merge operation.
			template<class T>
			static void MergeArray(T a[], T auxiliary[], int low, int middle, int high)
			{
				// Copy original array to auxiliary array.
				for (int i = low; i <= high; i++)
					auxiliary[i] = a[i];

				// Scanner of sub-array[low ... middle].
				int left = low;

				// Scanner of sub-array[middle+1 ... high].
				int right = middle + 1;

				// Merge back to data.
				for (int i = low; i <= high; i++)
				{
					if (left > middle)
						a[i] = auxiliary[right++];
					else if (right > high)
						a[i] = auxiliary[left++];
					else if (auxiliary[right] < auxiliary[left])
						a[i] = auxiliary[right++];
					else
						a[i] = auxiliary[left++];
				}
			}

			// Merge sort array[low ... high] using auxiliary array.
			// T : A generic type that is Comparable.
			// data : An int array.
			// auxiliary : An auxiliary array.
			// low : The lower limit of this merge operation.
			// high : The upper limit of this merge operation.
			template<class T>
			static void Sort(T a[], T auxiliary[], int low, int high)
			{
				// Returns if there is 1 or 0 element in the array.
				if (high <= low)
					return;

				// Get the middle index of the range to merge.
				int middle = (low + high) / 2;

				// Merge sort the left half.
				Sort(a, auxiliary, low, middle);

				// Merge sort the right half.
				Sort(a, auxiliary, middle + 1, high);

				// Merge results.
				MergeArray(a, auxiliary, low, middle, high);
			}

		public:
			// Re-arranges the array in ascending order.
			// T : A generity type that is Comparable.
			// a : The array to be sorted.
			// length : The length of the input array.
			template<class T>
			static void Sort(T a[], int length)
			{
				// Initialize the auxiliary array for merge sort.
				int * auxiliary = new int[length];

				// Merge sort the array using the auxiliary and count the number of inversions.
				Sort(a, auxiliary, 0, length - 1);

				// Release the memory of the auxiliary array.
				delete[] auxiliary;
			}
		};
	}
}