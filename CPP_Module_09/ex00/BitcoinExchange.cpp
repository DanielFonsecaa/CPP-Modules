#include "BitcoinExchange.hpp"

BitcoinEx::BitcoinEx() {
	loadData("data.csv");
}

BitcoinEx::~BitcoinEx(){
}

BitcoinEx::BitcoinEx(const BitcoinEx &other) {
	_data = other._data;
}

BitcoinEx &BitcoinEx::operator=(const BitcoinEx &other){
	if (this != &other)
		_data = other._data;
	return *this;
}

/*
double isValidValue(const std::string &value);
void process(char const *filename);
void getExchangeRate(const std::string &date);
*/

void BitcoinEx::loadData(const std::string &filename){
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw fileCannotOpen();
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw invalidFormat();
	std::string date, price;
	double priceValue;
	while(getline(file, line))
	{
		std::istringstream data(line);
		std::getline(data, date, ',');
		std::getline(data, price);

		if (!isValidDate(date))
			throw badInput(date);
		std::istringstream priceStream(price);
		if (!(priceStream >> priceValue))
			throw invalidFormat();
		_data[date] = priceValue;
	}
	file.close();
}

bool BitcoinEx::isValidDate(const std::string &date){
	struct tm time;
	if (!strptime(date.c_str(), "%Y-%m-%d", &time))
		return false;
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (year < 0 || month < 1 || month > 12 || day < 1 || day || 31)
		return false;
	int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[2] = 29;
	if (day > daysInMonth[month])
		return false;
	return true;
}
/*
void BitcoinEx::process(char const *filename){
	std::ifstream file(filename);
	if ()
}*/

BitcoinEx::badInput::badInput() : _message("Error: bad input => ") {}

BitcoinEx::badInput::badInput(const std::string &date)
	: _message("Error: bad input => " + date) {}

const char* BitcoinEx::badInput::what() const throw(){
	return _message.c_str();
};

const char* BitcoinEx::numberTooLarge::what() const throw(){
	return "Error: too large a number.\n";
};

const char* BitcoinEx::negativeNumber::what() const throw(){
	return "Error: not a positive number.\n";
};

const char* BitcoinEx::fileCannotOpen::what() const throw(){
	return "Error: could not open file.\n";
};

const char* BitcoinEx::invalidFormat::what() const throw(){
	return "Error: format is wrong.\ndata.csv should start with date,exchange_rate\n";
};

const char* BitcoinEx::invalidPriceFormat::what() const throw(){
	return "Error: price format is wrong. Expected a number between 0.00 and 1000.00\n";
};
