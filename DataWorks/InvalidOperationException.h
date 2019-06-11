#pragma once

#include <exception>
#include <string>

namespace DataWorks
{
	class InvalidOperationException : public std::runtime_error
	{
	public:
		explicit InvalidOperationException(const std::string& message) : runtime_error(message) {}
		explicit InvalidOperationException(const char* message) : runtime_error(message) {}
	};
}