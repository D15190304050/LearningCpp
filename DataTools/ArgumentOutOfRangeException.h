#pragma once

#include <exception>
#include <string>

namespace DataTools
{
	class ArgumentOutOfRangeException : public std::runtime_error
	{
	public:
		explicit ArgumentOutOfRangeException(const std::string& message) : runtime_error(message) {}
		explicit ArgumentOutOfRangeException(const char* message) : runtime_error(message) {}
	};
}