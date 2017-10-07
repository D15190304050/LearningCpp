#pragma once
#include "stdafx.h"

namespace DataAccess
{
	namespace MySql
	{
		// The MySqlConnectionTest class provides a static function for testing the connectioni for C++ to MySQL.
		class MySqlConnectionTest
		{
		private:
			// This class should not be instantiated.
			MySqlConnectionTest() {}

			// Desctructor.
			~MySqlConnectionTest() {}

		public:
			// The static function for testing the connection for C++ to MySQL.
			static void ConnectionTest();
		};
	}
}