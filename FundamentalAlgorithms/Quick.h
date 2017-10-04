#pragma once
#include "stdafx.h"
#include "SortBase.h"

namespace FundamentalAlgorithms
{
	namespace Sort
	{
		// The Quick class provides member function for sorting an array.
		class Quick
		{
		private:
			// A random number generator.
			StdRandom random;

			// Partitions the sub-array a[low ... high] so that a[low ... right-1] <= a[right] <= a[right+1 ... high]
			// and returns the index right.
			// T : A generic type that is Comparable.
			// a : The array to be sorted.
			// low : The lower limit of this sub-array.
			// high : The upper limit of this sub-array.
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

					SortBase::Swap(a, left, right);
				}

				// Put partitioning item at a[right].
				SortBase::Swap(a, low, right);

				// For now, a[low ... right-1] <= a[right] <= a[right+1 ... high].
				return right;
			}

			// Quick sort the sub-array from a[low] to a[high].
			// T : A generic type that is Comparable.
			// a : The array to be sorted.
			// low : The lower limit of this sub-array.
			// high : The upper limit of this sub-array.
			template<class T>
			static void Sort(T a[], int low, int high)
			{
				if (high <= low)
					return;

				// Partition.
				int partitioned = Partition(a, low, high);

				// Sort the left part array[low ... partitioned-1].
				Sort(a, low, partitioned - 1);

				// Sort the right part array[partitioned+1 ... high].
				Sort(a, partitioned + 1, high);
			}

		public:
			// Initializes a new quick sort solver.
			Quick() { random = StdRandom(); }

			// Destructor.
			~Quick() {}

			// Re-arranges the array in ascending order.
			// T : A generity type that is Comparable.
			// a : The array to be sorted.
			// length : The length of the input array.
			template<class T>
			void Sort(T a[], int length)
			{
				// Eliminate dependence on iunput.
				random.Shuffle(a, length);
				Sort(a, 0, length - 1);
			}
		};
	}
}