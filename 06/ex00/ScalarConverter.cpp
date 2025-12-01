#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
	double val = 0.0;
	bool err = false;
	std::string s = literal;

	const std::string specStr[] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
	const double specVal[] = {
		std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(),
		std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(),
		-std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity()
	};

	int idx = -1;
	for (int i = 0; i < 6; ++i) if (s == specStr[i]) idx = i;

	if (idx >= 0) val = specVal[idx];
	else if (s.length() == 1 && (s[0] < '0' || s[0] > '9') && s[0] >= 32 && s[0] <= 126)
		val = static_cast<double>(s[0]);
	else {
		if (s.length() > 1 && s[s.length() - 1] == 'f') s = s.substr(0, s.length() - 1);
		std::stringstream ss(s);
		ss >> val;
		if (ss.fail() || !ss.eof()) err = true;
	}

	std::cout << "char: ";
	(err || val != val || val < 0 || val > 127) ? std::cout << "impossible" 
	: (val < 32 || val > 126) ? std::cout << "Non displayable" 
	: std::cout << "'" << static_cast<char>(val) << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	(err || val != val || val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min()) ? std::cout << "impossible" 
	: std::cout << static_cast<int>(val);
	std::cout << std::endl;

	std::cout << "float: ";
	if (err) std::cout << "impossible";
	else {
		bool addZero = (val >= -1e6 && val <= 1e6 && val == static_cast<long>(val));
		
		val != val ? std::cout << "nanf" 
		: val == std::numeric_limits<double>::infinity() ? std::cout << "+inff" 
		: val == -std::numeric_limits<double>::infinity() ? std::cout << "-inff" 
		: std::cout << static_cast<float>(val) << (addZero ? ".0f" : "f");
	}
	std::cout << std::endl;

	std::cout << "double: ";
	if (err) std::cout << "impossible";
	else {
		bool addZero = (val >= -1e6 && val <= 1e6 && val == static_cast<long>(val));

		val != val ? std::cout << "nan" 
		: val == std::numeric_limits<double>::infinity() ? std::cout << "+inf" 
		: val == -std::numeric_limits<double>::infinity() ? std::cout << "-inf" 
		: std::cout << val << (addZero ? ".0" : "");
	}
	std::cout << std::endl;
}