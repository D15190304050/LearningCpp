#pragma once
#include "stdafx.h"

namespace DataAccess
{
	namespace MySql
	{
		class MySqlConnection
		{
		private:
			// The MySQL Server connection object.
			MYSQL conn;

			// A flag indicating whether this MySQL Server connection is closed.
			bool closed;

		public:
			// Gets or sets the connection string of this MySqlConnection instance.
			std::string ConnectionString;

			MySqlConnection() : MySqlConnection("") {};

			MySqlConnection(std::string connectionString);

			~MySqlConnection();
			
			void Open();

			void Close();

			static void InitializeEnvironment();

			static void EndEnvironment();
		};
	}
}