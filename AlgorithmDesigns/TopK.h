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
		static void Swap(int a[], int i, int j);

		static int Partition(int a[], int low, int high);

	public:
		// Initializes a new instance of the TopK class.
		TopK() { random = StdRandom(); }

		int * PartitionBasedSelection(int data[], int length, int k);
	};
}