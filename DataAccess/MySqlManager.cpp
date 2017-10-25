#pragma once
#include "stdafx.h"
#include "MySqlManager.h"

namespace DataAccess
{
	namespace MySql
	{
		void MySqlManager::InitializeEnvironment()
		{
			using namespace std;

			// Initialize the environment for database access with default (0, nullptr, nullptr) settings.
			// Throws runtime_error if an error occur when initialization.
			if (0 != mysql_library_init(0, nullptr, nullptr))
				throw runtime_error("Error occured when initializing the MySQL environment.");
		}

		void MySqlManager::EndEnvironment()
		{
			mysql_server_end();
		}
	}
}