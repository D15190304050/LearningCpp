#pragma once
#include "stdafx.h"
#include "SortBase.h"

namespace FundamentalAlgorithms
{
	namespace Sort
	{
		// The Insertion class provides static methods for sorting an array using insertion sort.
		class Insertion
		{
		private:
			// This class shouldn't be instantiated.
			Insertion() {}

		public:
			// Re-arranges the array in ascending order.
			// T : A generity type that is Comparable.
			// a : The array to be sorted.
			// length : The length of the input array.
			template<class T>
			static void Sort(T a[], int length)
			{
				for (int i = 0; i < length; i++)
				{
					// Insert a[i] among a[i - 1], a[i - 2], ...
					for (int j = i; j > 0; j--)
					{
						if (a[j] < a[j - 1])
							SortBase::Swap(a, j, j - 1);
						else
							break;
					}
				}
			}
		};
	}
}