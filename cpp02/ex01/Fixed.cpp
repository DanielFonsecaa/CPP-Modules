#include "Fixed.hpp"

Fixed::Fixed () : _value(0) {
	std::cout << "Default constructor called" << std::endl;
};


Fixed::~Fixed () {
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	_value = value << _frational;
};

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _frational));
};

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
};

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int Fixed::toInt(void) const
{
	return _value >> _frational;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _frational);
} 

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return out;
}