#pragma once
#include "stdafx.h"

namespace AlgorithmDesigns
{
	class AccumlateNumbers
	{
	private:
		int maxPegs;
		int * maxNumbers;

		void ComputeMaxNumbers();

	public:
		AccumlateNumbers(int maxPegs);

		~AccumlateNumbers() { delete[] maxNumbers; }

		int MaxNumbers(int maxPegs);
	};
}