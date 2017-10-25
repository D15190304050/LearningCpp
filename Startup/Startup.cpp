// Startup.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int main()
{
	using namespace std;

	int ** a;
	int numRow = 4;
	int numColumn = 5;

	a = (int **)malloc(sizeof(int *) * numRow);
	a[0] = (int *)malloc(sizeof(int) * numRow * numColumn);
	for (int i = 1; i < numRow; i++)
		a[i] = a[i - 1] + numColumn;

	for (int i = 0; i < numRow; i++)
	{
		for (int j = 0; j < numColumn; j++)
		{
			a[i][j] = i * numColumn + j;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	free(a[0]);
	free(a);

	// Keep the console window open in debug mode.
	system("pause");
    return 0;
}