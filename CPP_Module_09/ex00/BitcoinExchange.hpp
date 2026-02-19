#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <exception>
#include <algorithm>
#include <cctype>


class BitcoinEx {
	private:
		std::map<std::string, float> _data;
		bool isValidDate(const std::string &date);
		double isValidValue(const std::string &value);
		void loadData(const std::string &filename);
	public:
		BitcoinEx();
		~BitcoinEx();
		BitcoinEx(const BitcoinEx &src);
		BitcoinEx &operator=(const BitcoinEx &src);
		void process(char const *filename);
		void removeWhiteSpaces(std::string &str);
		float getRate(const std::string &date);
		class fileCannotOpen : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class negativeNumber : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class numberTooLarge : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class invalidFormat : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class invalidPriceFormat : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class invalidDateFormat : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};