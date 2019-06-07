//#pragma once
//#include "stdafx.h"
//#include "MySqlConnection.h"
//#include "..\DataWorks\LinkedList.h"
//
//namespace DataAccess
//{
//	namespace MySql
//	{
//		class MySqlCommand
//		{
//		private:
//			MySqlConnection conn;
//
//		public:
//			std::string CommandText;
//
//			MySqlCommand() : CommandText(""), conn(nullptr) {}
//
//			MySqlCommand(std::string & cmdText) : CommandText(cmdText), conn(nullptr) {}
//
//			MySqlCommand(std::string & cmdText, MySqlConnection & conn) : CommandText(cmdText), conn(conn) {}
//
//			DataWorks::Collections::LinkedList<std::string> ExecuteReader();
//
//			int ExecuteNonQuery();
//		};
//	}
//}