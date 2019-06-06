#pragma once
#include "stdafx.h"
//#include "MySqlConnection.h"
//
//namespace DataAccess
//{
//	namespace MySql
//	{
//
//		MySqlConnection::MySqlConnection(std::string connectionString)
//		{
//			using namespace std;
//		
//			conn = MYSQL();
//			ConnectionString = connectionString;
//			closed = false;
//
//			if (mysql_init(&conn) == nullptr)
//				throw runtime_error("Error occured when initializing a new MySQL connection.");
//
//			// Set the character set using the mysql_options() function with the MYSQL_SET_CHARSET_NAME option.
//			if (0 != mysql_options(&conn, MYSQL_SET_CHARSET_NAME, "utf8"))
//				throw runtime_error("Error occured when setting the charset for this MySQL connection.");
//		}
//
//		MySqlConnection::~MySqlConnection()
//		{
//			// Close the connection.
//			if (!closed)
//				mysql_close(&conn);
//		}
//
//		void MySqlConnection::Open()
//		{
//			using namespace std;
//
//			// Connect to MySQL with specified server, user, password, database, and port number.
//			// Keep nullptr and 0 at the end of the function as a default setting.
//			if (mysql_real_connect(&conn, "localhost", "DinoStark", "non-feeling", "startup", 3306, nullptr, 0) == nullptr)
//				throw runtime_error("Error occured when connecting to MySQL server.");
//		}
//
//		void MySqlConnection::Close()
//		{
//			closed = true;
//			mysql_close(&conn);
//		}
//	}
//}