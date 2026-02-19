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
	while(std::getline(file, line))
	{
		std::istringstream data(line);
		std::getline(data, date, ',');
		std::getline(data, price);
		if (!isValidDate(date))
			throw invalidDateFormat();
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
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[2] = 29;
	if (day > daysInMonth[month])
		return false;
	return true;
}

void BitcoinEx::process(char const *filename){
	std::ifstream file(filename);
	if (!file.is_open())
		throw fileCannotOpen();
	std::string line;
	if (!std::getline(file, line) || line != "date | value"){
		std::cerr << "[" << line << "] size=" << line.size() << std::endl;
		throw std::runtime_error("Error: bad header. Should be \"date | value\"");
	}
	while (std::getline(file, line))
	{
		std::string date, value;
		std::istringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, value);
		removeWhiteSpaces(date);
		removeWhiteSpaces(value);
		if (!(isValidDate(date)))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		try
		{
			double num = isValidValue(value);
			double rate = getRate(date);
			std::cout << date << " => " << num << " = " << rate * num << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			continue ;
		}
	}
	file.close();
}

bool isWhitespace(unsigned char c) {
	return std::isspace(c);
}

void BitcoinEx::removeWhiteSpaces(std::string &str){
	str.erase(std::remove_if(str.begin(), str.end(), isWhitespace), str.end());
}

float BitcoinEx::getRate(const std::string &date){
	std::map<std::string, float>::iterator it = _data.upper_bound(date);
	if (it == _data.begin())
		return 0;
	it--;
	return it->second;
};

double BitcoinEx::isValidValue(const std::string &value){
	char *end = NULL;
	double num = strtod(value.c_str(), &end);
	if (num <= 0.0)
		throw negativeNumber();
	if (num > 1000.0)
		throw numberTooLarge();
	return num;
};

const char* BitcoinEx::numberTooLarge::what() const throw(){
	return "Error: too large a number.";
};

const char* BitcoinEx::negativeNumber::what() const throw(){
	return "Error: not a positive number.";
};

const char* BitcoinEx::fileCannotOpen::what() const throw(){
	return "Error: could not open file.";
};

const char* BitcoinEx::invalidFormat::what() const throw(){
	return "Error: format is wrong.\ndata.csv should start with 'date,exchange_rate'.";
};

const char* BitcoinEx::invalidPriceFormat::what() const throw(){
	return "Error: price format is wrong. Expected a number between '0.00' and '1000.00'.";
};

const char* BitcoinEx::invalidDateFormat::what() const throw(){
	return "Invalid date format. Expected 'YYYY-MM-DD'.";
};