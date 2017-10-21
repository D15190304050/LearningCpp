#pragma once
#include "stdafx.h"
#include "MySqlConnection.h"

namespace DataAccess
{
	namespace MySql
	{
		void MySqlConnection::InitializeEnvironment()
		{
			using namespace std;

			// Initialize the environment for database access with default (0, nullptr, nullptr) settings.
			// Throws runtime_error if an error occur when initialization.
			if (0 != mysql_library_init(0, nullptr, nullptr))
				throw runtime_error("Error occured when initializing the MySQL environment.");
		}

		MySqlConnection::MySqlConnection(std::string connectionString)
		{
			using namespace std;
		
			conn = MYSQL();
			ConnectionString = connectionString;
			closed = false;

			if (mysql_init(&conn) == nullptr)
				throw runtime_error("Error occured when initializing a new MySQL connection.");

			// Set the character set using the mysql_options() function with the MYSQL_SET_CHARSET_NAME option.
			if (0 != mysql_options(&conn, MYSQL_SET_CHARSET_NAME, "utf8"))
				throw runtime_error("Error occured when setting the charset for this MySQL connection.");
		}

		MySqlConnection::~MySqlConnection()
		{
			// Close the connection.
			if (!closed)
				mysql_close(&conn);
		}

		void MySqlConnection::Open()
		{
			using namespace std;

			// Connect to MySQL with specified server, user, password, database, and port number.
			// Keep nullptr and 0 at the end of the function as a default setting.
			if (mysql_real_connect(&conn, "localhost", "DinoStark", "non-feeling", "startup", 3306, nullptr, 0) == nullptr)
				throw runtime_error("Error occured when connecting to MySQL server.");
		}

		void MySqlConnection::Close()
		{
			closed = true;
			mysql_close(&conn);
		}

		void MySqlConnection::EndEnvironment()
		{
			mysql_server_end();
		}
	}
}