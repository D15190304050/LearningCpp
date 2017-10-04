#pragma once
#include "stdafx.h"
#include "..\FundamentalAlgorithms\StdRandom.h"
#include "..\FundamentalAlgorithms\Quick.h"
#include "..\FundamentalAlgorithms\MinPriorityQueue.h"

using namespace FundamentalAlgorithms;

namespace AlgorithmDesigns
{
	// The TopK class represents a solution that provides several functions to deal with the top-k problems.
	class TopK
	{
	private:
		// A random number generator.
		StdRandom random;

		// Throws an exception if the length of the source data is not larger than k.
		// dataLength : The length of the source data.
		// k : The number of element to extract from cadicate data.
		static void LengthCheck(int dataLength, int k);

		// Swaps elements in the specified array with specified indicies.
		// T : A generic type that implements the operator<().
		// a : The array that contains the elements to swap.
		// i : The index of the element to swap.
		// j : The other index of the element to swap.
		template<class T>
		static void Swap(T a[], int i, int j)
		{
			T temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

		// Partion the sub-array array[low .. high] so that array[low .. j-1] &lt;= array[j] &lt;= array[j+1 .. high]
		// and return the index j, which is the correct index of the partitioning item.
		// T : A generic type that implements the operator<().
		// a : The array to partition.
		// low : The min index of the sub-array.
		// high : The max index of the sub-array.
		// Returns : The correct index of the partitioning item.
		template<class T>
		static int Partition(T a[], int low, int high)
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

	public:
		// Initializes a new instance of the TopK class.
		TopK() { random = StdRandom(); }

		// Sloves the top-k problem by partitioning the data.
		// T : A generic type that implements the operator<().
		// data : The array that contains the candicate data.
		// k : The number of element to extract from cadicate data.
		// Returns : A array that contains top-k element where k is specified by the caller.
		template<class T>
		T * PartitionBasedSelection(T data[], int length, int k)
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

			// Extract top-k elements.
			int * result = new int[k];
			for (int i = 0; i < k; i++)
				result[i] = data[length - 1 - i];

			return result;
		}

		// Solves the top-k problem by sorting the data.
		// T : A generic type that implements the operator<().
		// data : The array that contains the candicate data.
		// k : The number of element to extract from cadicate data.
		// Returns : A array that contains top-k element where k is specified by the caller.
		template<class T>
		T * SortBasedSelection(T data[], int length, int k)
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
	};
}