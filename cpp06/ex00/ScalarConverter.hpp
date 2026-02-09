#pragma once
#include <string>
#include <iostream>
#include <climits>
#include <cstring>
#include <cmath>
#include <limits>   // std::numeric_limits<T>::min/max
#include <cmath>    // std::isnan, std::isinf
#include <cstdlib>  // std::strtod
#include <cctype>   // std::isprint
#include <iomanip> 
#include <exception> // Not necessary but good pratice

class ScalarConverter
{
	private:
		int							type;
		int							_int;
		char						_char;
		float						_float;
		double						_double;
		const std::string			input;

		ScalarConverter();
		ScalarConverter(const std::string input);
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);

		int							checkInput(void);
		void						convertInput(void);

		void						isChar(void);
		void						isInt(void);
		void						isFloat(void);
		void						isDouble(void);

		std::string					getInput(void)const;
		int							getType(void)const;
		char						getChar(void)const;
		int							getInt(void)const;
		float						getFloat(void)const;
		double						getDouble(void)const;

		void						printOutput(void)const;
	public:
		static void 				convert(const std::string &input);
};