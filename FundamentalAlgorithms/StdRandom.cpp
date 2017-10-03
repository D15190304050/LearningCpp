#pragma once
#include "stdafx.h"
#include "StdRandom.h"
#include <ctime>
#include <stdexcept>

namespace FundamentalAlgorithms
{
	StdRandom::Random::Random()
	{
		seed = (unsigned)time(nullptr);
		srand(seed);
	}

	StdRandom::Random::Random(unsigned int seed)
	{
		this->seed = seed;
		srand(seed);
	}

	int StdRandom::Uniform(int minValue, int maxValue)
	{
		using namespace std;

		if (maxValue <= minValue)
			throw range_error("Invalid range.");
		if (((long)(maxValue - minValue)) > INT32_MAX)
			throw length_error("Invalid range");

		return minValue + Uniform(maxValue - minValue);
	}

	double StdRandom::Uniform(double minValue, double maxValue)
	{
		using namespace std;

		if (maxValue <= minValue)
			throw range_error("Invalid range.");

		return minValue + NextDouble() * (maxValue - minValue);
	}
}