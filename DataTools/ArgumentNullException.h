#pragma once

#include <exception>
#include <string>

namespace DataTools
{
	class ArgumentNullException : public std::runtime_error
	{
	public:
		explicit ArgumentNullException(const std::string& message) : runtime_error(message) {}
		explicit ArgumentNullException(const char* message) : runtime_error(message) {}
	};
}