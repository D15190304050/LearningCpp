#pragma once
#include "stdafx.h"

namespace AlgorithmDesigns
{
	class NumberOfInversions
	{
	private:
		static int MergeArray(int data[], int auxiliary[], int low, int middle, int high);

		static void MergeSort(int data[], int axuiliary[], int low, int high, int * count);

	public:
		static int MergeBasedCount(int data[], int length);
	};
}