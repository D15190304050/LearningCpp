#pragma once
#include "stdafx.h"

namespace FundamentalAlgorithms
{
	class StdRandom
	{
	private:


	public:
		static int Uniform(int n);

		template<class T>
		static void Shuffle<T>(T array[], int length);
	};
}