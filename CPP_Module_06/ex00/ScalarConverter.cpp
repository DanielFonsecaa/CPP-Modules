#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter(){
	std::cout << "ScalarConverter destructor" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string input) : input(input)
{
	std::cout << "ScalarConverter name constructor" << std::endl;
	type = checkInput();
	convertInput();
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : input(other.getInput())
{
	std::cout << "ScalarConverter copy constructor" << std::endl;
	type = other.type;
	_char = other._char;
	_int = other._int;
	_float = other._float;
	_double = other._double;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
	std::cout << "ScalarConverter copy assignment" << std::endl;
	if (this != &other)
	{
		type = other.type;
		_char = other._char;
		_int = other._int;
		_float = other._float;
		_double = other._double;
	}
	return *this;
}

std::string ScalarConverter::getInput()const { return input; }
int ScalarConverter::getType()const { return type; }
char ScalarConverter::getChar()const { return _char; }
int ScalarConverter::getInt()const { return _int; }
float ScalarConverter::getFloat()const { return _float; }
double ScalarConverter::getDouble()const { return _double; }

void ScalarConverter::convert(const std::string &input)
{
	ScalarConverter sc(input);
}

static bool isStrictInt(const std::string& s)
{
	if (s.empty())
		return false;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.size())
		return false;
	for (; i < s.size(); i++)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	return true;
}

int ScalarConverter::checkInput()
{
	const std::string& s = input;

	// pseudo
	if (s == "-inf" || s == "+inf" || s == "-inff" || s == "+inff" ||
		s == "nan"  || s == "nanf")
		return -1;
	// single char literal
	if (s.size() == 1 && std::isprint(static_cast<unsigned char>(s[0])) &&
		!std::isdigit(static_cast<unsigned char>(s[0])) &&
		s[0] != '+' && s[0] != '-' && s[0] != '.' && s[0] != 'f')
		return 1; //CHAR
	if (isStrictInt(s))
		return 2; //INT
	bool hasF = (!s.empty() && s[s.size() - 1] == 'f');
	bool hasDot = (s.find('.') != std::string::npos);
	std::string toParse = s;
	if (hasF)
		toParse = s.substr(0, s.size() - 1);
	char *end = NULL;
	std::strtod(toParse.c_str(), &end);
	// end must point to string end -> fully parsed 42.5asdsa = 42.5  abc = 0.0
	if (end == NULL || *end != '\0')
		return 0;
	// Require a dot for float/double
	if (!hasDot)
		return 0;
	return hasF ? 4 : 3; // 4 float, 3 double
}

void ScalarConverter::convertInput()
{
	switch (type)
	{
		case 0:
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
			return;
		case 1:
			isChar();
			break;
		case 2:
			isInt();
			break;
		case -1:
		case 3:
			isDouble();
			break;
		case 4:
			isFloat();
			break;
		default:
			return;
	}
}

void ScalarConverter::isChar()
{
	_char = input[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
	printOutput();
}

void ScalarConverter::isInt()
{
	// parse safely using strtod then cast after checks
	char *end = NULL;
	double d = std::strtod(input.c_str(), &end);
	_double = d;
	_float = static_cast<float>(_double);

	if (!std::isnan(_double) && !std::isinf(_double) &&
		_double >= std::numeric_limits<int>::min() &&
		_double <= std::numeric_limits<int>::max())
		_int = static_cast<int>(_double);
	else
		_int = 0; // value won't be used when printing "impossible"

	_char = static_cast<char>(_int);
	printOutput();
}

void ScalarConverter::isFloat()
{
	// strip trailing 'f' and parse as double
	std::string s = input.substr(0, input.size() - 1);
	char *end = NULL;
	_double = std::strtod(s.c_str(), &end);
	_float = static_cast<float>(_double);

	if (!std::isnan(_double) && !std::isinf(_double) &&
		_double >= std::numeric_limits<int>::min() &&
		_double <= std::numeric_limits<int>::max())
		_int = static_cast<int>(_double);
	else
		_int = 0;

	_char = static_cast<char>(_int);
	printOutput();
}

void ScalarConverter::isDouble()
{
	char *end = NULL;
	_double = std::strtod(input.c_str(), &end);
	_float = static_cast<float>(_double);

	if (!std::isnan(_double) && !std::isinf(_double) &&
		_double >= std::numeric_limits<int>::min() &&
		_double <= std::numeric_limits<int>::max())
		_int = static_cast<int>(_double);
	else
		_int = 0;

	_char = static_cast<char>(_int);
	printOutput();
}

void ScalarConverter::printOutput(void)const
{
	//CHAR
	std::cout << "char: ";
	if(getType() != -1 && getDouble() <= UCHAR_MAX && getDouble() >= 0)
	{
		if(std::isprint(static_cast<unsigned char>(getChar())))
			std::cout << "'" << getChar() << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	//INT
	std::cout << "int: ";
	if(getType() != -1 && getDouble() >= std::numeric_limits<int>::min() && getDouble() <= std::numeric_limits<int>::max())
		std::cout << getInt() << std::endl;
	else
		std::cout << "impossible" << std::endl;
	//FLOAT
	std::cout << "float: ";
	if(getType() != -1)
		if(getDouble() - getInt() == 0)
			std::cout << getFloat() << ".0f" << std::endl;
		else
			std::cout << getFloat() << "f" << std::endl;
	else
	{
		if(getInput() == "nan" || getInput() == "nanf")
			std::cout << "nanf" << std::endl;
		else if (getInput()[0] == '+')
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	//DOUBLE
	std::cout << "double: ";
	if(getType() != -1)
	{
		std::cout << getDouble();
		if(getDouble() - getInt() == 0 || getDouble() < std::numeric_limits<double>::min() || getDouble() > std::numeric_limits<double>::max())
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		if(getInput() == "nan" || getInput() == "nanf")
			std::cout << "nan" << std::endl;
		else if (getInput()[0] == '+')
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
}