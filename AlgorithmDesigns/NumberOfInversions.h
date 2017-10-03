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
		// data : An int array.
		// auxiliary : An auxiliary array.
		// low : The lower limit of this merge operation.
		// high : The upper limit of this merge operation.
		// Returns : The number of inversions in sub-array[low ... high].
		static int MergeArray(int data[], int auxiliary[], int low, int middle, int high);

		// Merge sort array[low ... high] using auxiliary array.
		// data : An int array.
		// auxiliary : An auxiliary array.
		// low : The lower limit of this merge operation.
		// high : The upper limit of this merge operation.
		// count : The counter that computes the number of inversions.
		static void MergeSort(int data[], int axuiliary[], int low, int high, int * count);

	public:
		// Solves the number of inversions problem using merge sort.
		// data : An int array.
		// length : The length of the input array.
		// Returns : The number of inversions of the specified array.
		static int MergeBasedCount(int data[], int length);
	};
}