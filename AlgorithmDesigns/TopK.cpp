#pragma once
#include "stdafx.h"
#include "TopK.h"
#include <stdexcept>

namespace AlgorithmDesigns
{
	void TopK::LengthCheck(int dataLength, int k)
	{
		using namespace std;

		if (dataLength < k)
			throw runtime_error("The length of the source data must be larger than k.");
	}
}