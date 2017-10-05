#pragma once
#include "stdafx.h"
#include "..\FundamentalAlgorithms\StdRandom.h"
#include "..\FundamentalAlgorithms\Quick.h"
#include "..\FundamentalAlgorithms\MinPriorityQueue.h"
#include "..\FundamentalAlgorithms\Merge.h"

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
		// T : A generic type that is Comparable.
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
		// T : A generic type that is Comparable.
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

				// Swap them.
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

		// Destructor.
		~TopK() {}

		// Sloves the top-k problem by partitioning the data.
		// T : A generic type that is Comparable.
		// data : The array that contains the candicate data.
		// k : The number of element to extract from cadicate data.
		// Returns : A array that contains top-k element where k is specified by the caller.
		template<class T>
		T * PartitionBasedExtraction(T data[], int length, int k)
		{
			using namespace FundamentalAlgorithms::Sort;

			// Check length before processing.
			LengthCheck(length, k);

			// Shuffle the data before partitioning them.
			random.Shuffle(data, length);

			// Initialize the partition range.
			int low = 0;
			int high = length - 1;

			// Loop until get some element partitioned with index (data.Length - k).
			for (;;)
			{
				// Partition some element and get its index.
				int partitionedIndex = Partition(data, low, high);

				// Update the partition range if the index of the partitioned element is not data.Length - k,
				// break otherwise.
				if (partitionedIndex > length - k)
					high = partitionedIndex - 1;
				else if (partitionedIndex < length - k)
					low = partitionedIndex + 1;
				else
					break;
			}

			// Extract top-k elements.
			int * result = new int[k];
			for (int i = 0; i < k; i++)
				result[i] = data[length - 1 - i];

			// Merge sort the extracted elements.
			Merge::Sort(result, k);

			// Reverse the order of the sorted elements.
			T * reverse = new T[k];
			for (int i = 0; i < k; i++)
				reverse[i] = result[k - 1 - i];
			delete[] result;
			result = reverse;

			return result;
		}

		// Solves the top-k problem by sorting the data.
		// T : A generic type that is Comparable.
		// data : The array that contains the candicate data.
		// k : The number of element to extract from cadicate data.
		// Returns : A array that contains top-k element where k is specified by the caller.
		template<class T>
		T * SortBasedExtraction(T data[], int length, int k)
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

		// Solves the top-k problem by using a min priority queue.
		// T : A generic type that is Comparable.
		// data : The array that contains the candicate data.
		// k : The number of element to extract from cadicate data.
		// Returns : A array that contains top-k element where k is specified by the caller.
		template<class T>
		T * MinPQBasedExtraction(T data[], int length, int k)
		{
			using namespace FundamentalAlgorithms::Sort;

			// Check the length before processing.
			LengthCheck(length, k);

			// Initialize an empty min priority queue.
			MinPriorityQueue<T> queue;

			// Declare a variable as the loop-counter.
			int i = 0;

			// Insert (k + 1) items in the source data.
			while (i < k + 1)
			{
				// Add next item to the source data.
				queue.Add(data[i]);

				// Update the loop-counter;
				i++;
			}

			// Filter the data.
			while (i < length)
			{
				// Remove the min elemet from the priority queue.
				// Because there are (k + 1) elements in the priority queue, remove the min element will make sure that
				// the current top-k elements are still in the priority queue.
				queue.DeleteMin();

				// Add next item in the source data.
				queue.Add(data[i]);

				// Update the loop-counter.
				i++;
			}

			// For now, we have the top-(k+1) elements in the priority queue.
			// We can get the top-k elements by calling the DeleteMin() method again.
			queue.DeleteMin();

			// Extract the top-k elements from the priority queue.
			T * result = new int[k];
			for (i = 0; i < k; i++)
				result[k - 1 - i] = queue.DeleteMin();

			return result;
		}

		// Solves the top-k problem by using a min priority queue.
		// T : A generic type that is Comparable.
		// data : The array that contains the candicate data.
		// k : The number of element to extract from cadicate data.
		// Returns : A array that contains top-k element where k is specified by the caller.
		template<class T>
		T * MinPQBasedExtraction2(T data[], int length, int k)
		{
			using namespace FundamentalAlgorithms::Sort;

			// Check the length before processing.
			LengthCheck(length, k);

			// Initialize an empty min priority queue.
			MinPriorityQueue<T> queue;

			// Declare a variable as the loop-counter.
			int i = 0;

			// Insert k item into the priorityqueue.
			while (i < k)
			{
				// Add next item to the priority queue.
				queue.Add(data[i]);

				// Update the loop-counter.
				i++;
			}

			// Filter the data.
			while (i < length)
			{
				// Get the min element on the priority queue.
				T min = queue.Min();

				// Remove the min element if it is less than the next item in the input array.
				// And then add the item to the priority queue.
				if (min < data[i])
				{
					queue.DeleteMin();
					queue.Add(data[i]);
				}

				// Update the loop-counter.
				i++;
			}

			// Extract the top-k elements from the priority queue.
			T * result = new T[k];
			for (i = 0; i < k; i++)
				result[k - 1 - i] = queue.DeleteMin();

			return result;
		}
	};
}