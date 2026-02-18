#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <exception>
#include <cmath>


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
		void getExchangeRate(const std::string &date);
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
		class badInput : public std::exception
		{
			public:
				badInput();
				badInput(const std::string &date);
				virtual const char *what() const throw();
			private:
				std::string _message;
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
};