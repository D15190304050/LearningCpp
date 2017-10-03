#pragma once
#include "stdafx.h"
#include "StdRandom.h"
#include <ctime>
#include <stdexcept>

namespace FundamentalAlgorithms
{
	StdRandom::Random::Random(unsigned int seed)
	{
		this->seed = seed;
		srand(seed);
	}

	int StdRandom::Random::NextInt()
	{
		return rand();
	}

	int StdRandom::Random::NextInt(int maxValue)
	{
		return rand() % maxValue;
	}

	double StdRandom::Random::NextDouble()
	{
		return rand() / ((double)RAND_MAX);
	}

	int StdRandom::Uniform(int minValue, int maxValue)
	{
		using namespace std;

		if (maxValue <= minValue)
			throw range_error("Invalid range.");
		if (((long)(maxValue - minValue)) > INT32_MAX)
			throw length_error("Invalid range");

		return minValue + random.NextInt(maxValue - minValue);
	}

	double StdRandom::Uniform(double minValue, double maxValue)
	{
		using namespace std;

		if (maxValue <= minValue)
			throw range_error("Invalid range.");

		return minValue + NextDouble() * (maxValue - minValue);
	}
}