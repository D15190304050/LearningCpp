#include "stdafx.h"
#include "MySqlConnectionTest.h"

int main()
{
	using namespace DataAccess::MySql;

	MySqlConnectionTest::ConnectionTest();
	
	// Keep the console window open in debug mode.
	system("pause");
	return 0;
}