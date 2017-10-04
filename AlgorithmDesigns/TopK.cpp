#pragma once
#include "stdafx.h"
#include "TopK.h"
#include "Quick.h"
#include <stdexcept>

namespace AlgorithmDesigns
{
	void TopK::LengthCheck(int dataLength, int k)
	{
		using namespace std;

		if (dataLength < k)
			throw runtime_error("The length of the source data must be larger than k.");
	}

	template<class T>
	void TopK::Swap(T a[], int i, int j)
	{
		T temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	template<class T>
	int TopK::Partition(T a[], int low, int high)
	{
		// Left and right scan indicies.
		int left = low;
		int right = high + 1;

		// Partitioning item with index low.
		int pItem = a[low];

		// The partition procedure.
		for (;;)
		{
			// Find the item on left to swap.
			while (a[++left] < pItem)
			{
				if (left == high)
					break;
			}

			// Find the item on right to swap.
			while (pItem < a[--right])
			{
				if (low == right)
					break;
			}

			// Check if pointers cross.
			if (right <= left)
				break;

			Swap(a, left, right);
		}

		// Put partitioning item at a[right].
		Swap(a, low, right);

		// For now, a[low ... right-1] <= a[right] <= a[right+1 ... high].
		return right;
	}

	int * TopK::PartitionBasedSelection(int data[], int length, int k)
	{
		// Check length before processing.
		LengthCheck(length, k);

		// Shuffle the data before partitioning them.
		random.Shuffle(data, length);

		// Initialize the partition range.
		int low = 0;
		int high = length - 1;

		// Make a deep copy of k, because the length of the remaining elements to
		int remainingCount = k;

		// Loop until get some element partitioned with index (data.Length - k).
		for (;;)
		{
			// Partition some element and get its index.
			int partitionedIndex = Partition(data, low, high);

			// Update the partition range if the index of the partitioned element is not data.Length - k,
			// break otherwise.
			if (partitionedIndex > high - remainingCount)
			{
				remainingCount = remainingCount - (high - partitionedIndex + 1);
				high = partitionedIndex - 1;
			}
			else if (partitionedIndex < high - remainingCount)
				low = partitionedIndex + 1;
			else
				break;
		}

		int * result = new int[k];
		for (int i = 0; i < k; i++)
			result[i] = data[length - 1 - i];

		return result;
	}

	int * TopK::SortBasedSelection(int data[], int length, int k)
	{
		using namespace FundamentalAlgorithms::Sort;

		// Check the length before processing.
		LengthCheck(length, k);

		// Sort the data.
		Quick quick;
		quick.Sort(data, length);

		// Extract top-k elements.
		int * result = new int[k];
		for (int i = 0; i < k; i++)
			result[i] = data[length - 1 - i];

		return result;
	}
}