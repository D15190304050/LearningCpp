#include "stdafx.h"
//#include "MySqlConnectionTest.h"
//
//namespace DataAccess
//{
//	namespace MySql
//	{
//		void MySqlConnectionTest::ConnectionTest()
//		{
//			using namespace std;
//
//			// A necessary data structure to store the intermediate results of SQL clauses.
//			MYSQL mydata;
//
//			// Initialize the environment for database access with default (0, nullptr, nullptr) settings.
//			if (0 == mysql_library_init(0, nullptr, nullptr))
//				cout << "mysql_library_init() succeed" << endl;
//			else
//			{
//				cout << "mysql_library_init() failed" << endl;
//				std::system("pause");
//				exit(-1);
//			}
//
//			// Initialize the data structure for intermediate results.
//			if (mysql_init(&mydata) == nullptr)
//			{
//				cout << "mysql_init() failed" << endl;
//				std::system("pause");
//				exit(-2);
//			}
//			else
//				cout << "mysql_init() succeed" << endl;
//
//			// Set the character set using the mysql_options() function with the MYSQL_SET_CHARSET_NAME option.
//			if (0 == mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "utf8"))
//				cout << "mysql_options() succeed" << endl;
//			else
//			{
//				cout << "mysql_options() failed" << endl;
//				std::system("pause");
//				exit(-3);
//			}
//
//			// Connect to MySQL with specified server, user, password, database, and port number.
//			// Keep nullptr and 0 at the end of the function as a default setting.
//			if (mysql_real_connect(&mydata, "localhost", "DinoStark", "non-feeling", "startup", 3306, nullptr, 0) == nullptr)
//			{
//				cout << "mysql_real_connect() failed" << endl;
//				std::system("pause");
//				exit(-4);
//			}
//			else
//				cout << "mysql_real_connect() succeed" << endl;
//
//			// Try to create a table.
//			string createTable = "Create Table If Not Exists Keyboards";
//			createTable += "(";
//			createTable += "    ID int Primary Key,";
//			createTable += "    Name VarChar(20),";
//			createTable += "    SwitchType VarChar(20)";
//			createTable += ");";
//			if (0 == mysql_query(&mydata, createTable.c_str()))
//				cout << "mysql_query() create table succeed" << endl;
//			else
//			{
//				cout << "mysql_query() create table failed" << endl;
//				std::system("pause");
//				exit(-5);
//			}
//
//			// Try to insert values to the table we created before.
//			string insertValues = "Insert Into Keyboards Values (1, 'Strafe Red', 'Red Axis'), (2, 'Strafe RGB', 'Blue Axis');";
//			if (0 == mysql_query(&mydata, insertValues.c_str()))
//				cout << "mysql_query() insert data succeed." << endl;
//			else
//			{
//				cout << "mysql_query() insert failed" << endl;
//				std::system("pause");
//				exit(-6);
//			}
//
//			// Try to get values from the table.
//			string query = "Select * From Keyboards;";
//			MYSQL_RES * result = nullptr;
//			if (0 == mysql_query(&mydata, query.c_str()))
//			{
//				cout << "mysql_query() select data succeed" << endl;
//
//				// Get the query result from the data structure.
//				result = mysql_store_result(&mydata);
//
//				// Get the number of rows selected.
//				unsigned long long int rowCount = mysql_num_rows(result);
//				cout << "Row Count: " << rowCount << endl;
//
//				// Get the number of fields.
//				unsigned int fieldCount = mysql_num_fields(result);
//
//				// Print fields of the table we created before.
//				MYSQL_FIELD * field = nullptr;
//				for (unsigned int i = 0; i < fieldCount; i++)
//				{
//					field = mysql_fetch_field_direct(result, i);
//					cout << field->name << "\t\t";
//				}
//				cout << endl;
//
//				// Print rows in the table.
//				MYSQL_ROW row = nullptr;
//				row = mysql_fetch_row(result);
//				while (row != nullptr)
//				{
//					for (unsigned int i = 0; i < fieldCount; i++)
//						cout << row[i] << "\t\t";
//					cout << endl;
//					row = mysql_fetch_row(result);
//				}
//			}
//			else
//			{
//				cout << "mysql_query() select data failed" << endl;
//				std::system("pause");
//				exit(-7);
//			}
//
//			// Drop the table we created before.
//			string dropTable = "DROP TABLE Keyboards;";
//			if (0 == mysql_query(&mydata, dropTable.c_str()))
//				cout << "mysql_query() drop table succeed" << endl;
//			else
//			{
//				cout << "mysql_query() drop table failed" << endl;
//				std::system("pause");
//				exit(-8);
//			}
//
//			// Clean up operations.
//			mysql_free_result(result);
//			mysql_close(&mydata);
//			mysql_server_end();
//		}
//	}
//}