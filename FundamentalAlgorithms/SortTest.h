#pragma once
#include "stdafx.h"
#include "Quick.h"
#include "MinPriorityQueue.h"

namespace FundamentalAlgorithms
{
	namespace Sort
	{
		class SortTest
		{
		public:
			// Functionality test function for the quick sort algorithm.
			static void QuickSortFunctionalityTest();
			
			// Functionality test function for the MinPriorityQueue class.
			static void MinPQFunctionalityTest();

			// Functionality test function for the insertion sort algorithm.
			static void InsertionSortFunctionalityTest();

			// Functionality test function for the insertion sort algorithm.
			static void MergeSortFunctionalityTest();
		};
	}
}