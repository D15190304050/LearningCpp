// Startup.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void output(int * ar, int m)
{
	for (int i = 0; i < m; i++)
	{
		if (*(ar + i))
			printf("%2d", i + 1);
	}
	putchar('\n');
}

int check(int * ar, int m, int n)
{
	for (int i = 0; i < (m - n); i++)
	{
		if (*(ar + i))
			return 1;
	}
	return 0;
}

void combination(int * ar, int m, int n)
{
	while (check(ar, m, n))
	{
		int count = 0;
		int i;

		output(ar, m);
		for (i = 0; i < (m - 1); i++)
		{
			if (*(ar + i) == 1 && *(ar + i + 1) == 0)
			{
				*(ar + i) = 0;
				*(ar + i + 1) = 1;
				break;
			}
			if (*(ar + i))
				count++;
		}
		for (int j = 0; j < i; j++)
		{
			if (j < count)
				*(ar + j) = 1;
			else
				*(ar + j) = 0;//从break下的if()开始，count记录i之前的‘1’出现的次数，然后在这里赋值
		}
	}
	output(ar, m);
}

int main()
{
	using namespace std;

	

	// Keep the console window open in debug mode.
	system("pause");
    return 0;
}