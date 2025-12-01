#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();

	public:
		static void convert(const std::string &literal);
};