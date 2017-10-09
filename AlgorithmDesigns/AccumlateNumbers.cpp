#pragma once;
#include "stdafx.h"
#include "AccumlateNumbers.h"

namespace AlgorithmDesigns
{
	void AccumlateNumbers::ComputeMaxNumbers()
	{
		maxNumbers[1] = 1;

		if (maxPegs == 1)
			return;
		else if (maxPegs == 2)
			maxNumbers[2] = 3;
		else if (maxPegs > 2)
		{
			maxNumbers[2] = 3;

			for (int i = 3; i <= maxPegs; i++)
			{
				if (i % 2 == 0)
					maxNumbers[i] = maxNumbers[i - 1] + i;
				else
					maxNumbers[i] = maxNumbers[i - 1] + i + 1;
			}
		}
	}

	AccumlateNumbers::AccumlateNumbers(int maxPegs)
	{
		using namespace std;

		if (maxPegs < 1)
			throw runtime_error("The number of max pegs must be a positive integer.");

		this->maxPegs = maxPegs;
		maxNumbers = new int[maxPegs + 1];

		ComputeMaxNumbers();
	}

	int AccumlateNumbers::MaxNumbers(int maxPegs)
	{
		using namespace std;

		if (maxPegs > this->maxPegs)
			throw runtime_error("The number of max pegs is too large.");

		return maxNumbers[maxPegs];
	}
}