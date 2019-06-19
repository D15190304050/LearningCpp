#pragma once

#include <exception>
#include <string>

namespace DataWorks
{
	class ArgumentException : public std::runtime_error
	{
	public:
		explicit ArgumentException(const std::string& message) : runtime_error(message) {}
		explicit ArgumentException(const char* message) : runtime_error(message) {}
	};
}