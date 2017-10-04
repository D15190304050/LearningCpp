#pragma once
#include "stdafx.h"

namespace FundamentalAlgorithms
{
	namespace Sort
	{
		// The MinPriorityQueue class represents a priority queue of generic keys.
		// Remarks : It supports the usual add and delete-the-minimum operations.
		template<class TKey>
		class MinPriorityQueue
		{
		private:
			// Store items at indicies 1 to count.
			TKey * priorityQueue;

			// The length of the heap array.
			int length;

			// Number of items on priority queue.
			int count;

			MinPriorityQueue operator=(MinPriorityQueue mpq) = delete;

			// Helper function to adjust the size of the heap array.
			// capacity : The capacity of the heap array after adjustment.
			void Resize(int capacity)
			{
				using namespace std;

				// Throw an exception if the target capacity is less than the number of items on this priority queue.
				// Actually, this exception will not be thrown.
				if (capacity <= count)
					throw length_error("The capacity must be greater than the number of items on this priority queue.");

				// Update the length.
				length = capacity;

				// Copy items to the new priority queue.
				TKey * newQueue = new TKey[capacity];
				for (int i = 1; i <= count; i++)
					newQueue[i] = priorityQueue[i];

				// Change the pointer and release the memory.
				TKey * oldQueue = priorityQueue;
				priorityQueue = newQueue;
				delete[] oldQueue;
			}

			/* Helper functions for compares and swaps. */

			// Swaps items on this priority queue with indicies i and j.
			// i : An index.
			// j : The other index.
			void Swap(int i, int j)
			{
				TKey temp = priorityQueue[i];
				priorityQueue[i] = priorityQueue[j];
				priorityQueue[j] = temp;
			}

			/* Helper functions to restore the heap invariant. */

			// Make the object swim to proper position.
			// index : The index of the element.
			void Swim(int index)
			{
				while ((index > 1) && (priorityQueue[index / 2] > priorityQueue[index]))
				{
					Swap(index / 2, index);
					index /= 2;
				}
			}

			// Make the object sink to proper position.
			// index : The index of the element.
			void Sink(int index)
			{
				while (2 * index <= count)
				{
					int nextIndex = 2 * index;
					if ((nextIndex < count) && (priorityQueue[nextIndex] > priorityQueue[nextIndex + 1]))
						nextIndex++;

					if (!(priorityQueue[index] > priorityQueue[nextIndex]))
						break;

					Swap(index, nextIndex);

					index = nextIndex;
				}
			}

		public:
			// Initializes an empty priority queue with the given initial capacity.
			// initCapacity : The initial capacity of this priority queue.
			MinPriorityQueue(int initCapacity)
			{
				length = initCapacity + 1;
				priorityQueue = new TKey[length];
				count = 0;
			}

			// Initializes an empty priority queue.
			MinPriorityQueue() : MinPriorityQueue(1) {}

			// Initializes a priority queue from the array of keys.
			// Remarks : Takes time proportional to the number of keys, using sink-based heap construction.
			// keys : The array of keys.
			// length : The length of the input array.
			MinPriorityQueue(TKey keys[], int length)
			{
				this->length = length;
				count = length;
				priorityQueue = new TKey[length + 1];
				for (int i = 0; i < length; i++)
					priorityQueue[i + 1] = keys[i];
				for (int k = count / 2; k >= 1; k--)
					Sink(k);
			}

			~MinPriorityQueue()
			{
				delete[] priorityQueue;
			}

			// Returns true if this priority queue is empty, false otherwise.
			bool IsEmpty() const { return count == 0; }

			// Returns the number of keys on this priority queue.
			int Count() const { return count; }

			// Returns a smallest key on this priority queue.
			// Throws underflow_error if this priority queue is empty.
			TKey Min()
			{
				using namespace std;

				if (count == 0)
					throw underflow_error("Priority queue underflow");

				return priorityQueue[1];
			}

			// Adds a new key to this priority queue.
			// key : The key to add to this priority queue.
			void Add(TKey key)
			{
				// Double size of array if necessary.
				if (count == length - 1)
					Resize(2 * length);

				// Add key, and percolate it up to maintain heap invariant.
				priorityQueue[++count] = key;
				Swim(count);
			}

			// Removes and returns a smallest key on this priority queue.
			// Throws underflow_error if this priority queue is empty.
			TKey DeleteMin()
			{
				using namespace std;

				if (count == 0)
					throw underflow_error("Priority queue underflow");

				Swap(1, count);
				TKey min = priorityQueue[count--];
				Sink(1);

				if ((count > 0) && (count <= (length - 1) / 4))
					Resize(length / 2);

				return min;
			}
		};
	}
}