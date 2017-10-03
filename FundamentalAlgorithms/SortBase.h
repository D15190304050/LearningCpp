#pragma once

namespace FundamentalAlgorithms
{
	namespace Sort
	{
		class SortBase
		{
		public:
			// Swap objects in the given array with the given index i and j.
			// T : The type of object to swap.
			// a : The given that stores the objects to swap.
			// i : An index of objects to swap.
			// j : The other index of object to swap.
			template<class T>
			static void Swap(T a[], int i, int j)
			{
				T temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		};
	}
}