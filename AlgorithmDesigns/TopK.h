#pragma once
#include "stdafx.h"
#include "..\FundamentalAlgorithms\StdRandom.h"

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
		// a : The array that contains the elements to swap.
		// i : The index of the element to swap.
		// j : The other index of the element to swap.
		template<class T>
		static void Swap(T a[], int i, int j);

		// Partion the sub-array array[low .. high] so that array[low .. j-1] &lt;= array[j] &lt;= array[j+1 .. high]
		// and return the index j, which is the correct index of the partitioning item.
		// a : The array to partition.
		// low : The min index of the sub-array.
		// high : The max index of the sub-array.
		// Returns : The correct index of the partitioning item.
		template<class T>
		static int Partition(T a[], int low, int high);

	public:
		// Initializes a new instance of the TopK class.
		TopK() { random = StdRandom(); }

		// Sloves the top-k problem by partitioning the data.
		// data : The array that contains the candicate data.
		// k : The number of element to extract from cadicate data.
		// Returns : A array that contains top-k element where k is specified by the caller.
		int * PartitionBasedSelection(int data[], int length, int k);

		// Solves the top-k problem by sorting the data.
		// data : The array that contains the candicate data.
		// k : The number of element to extract from cadicate data.
		// Returns : A array that contains top-k element where k is specified by the caller.
		int * SortBasedSelection(int data[], int length, int k);
	};
}