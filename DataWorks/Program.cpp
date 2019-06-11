#include <iostream>
#include "common.h"

int main()
{
	using namespace std;
	using namespace DataWorks;

	try
	{
		throw InvalidOperationException("Damn it.");
	}
	catch (InvalidOperationException e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}