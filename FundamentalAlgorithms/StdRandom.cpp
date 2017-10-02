#pragma once
#include "stdafx.h"
#include "StdRandom.h"
#include <ctime>

namespace FundamentalAlgorithms
{
	template<class T>
	void StdRandom::Shuffle(T a[], int length)
	{
		using namespace std;

		srand((unsigned)time(nullptr));
		for (int i = 0; i < length; i++)
		{
			//int indexToSwap = ran
		}
	}
}