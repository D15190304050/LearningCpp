#pragma once
#include "stdafx.h"
#include "SortBase.h"

namespace FundamentalAlgorithms
{
	namespace Sort
	{
		class Quick
		{
		private:
			StdRandom random;

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
			Quick() { random = StdRandom(); }
			~Quick() {}

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