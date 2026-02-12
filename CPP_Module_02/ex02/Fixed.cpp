#include "Fixed.hpp"

Fixed::Fixed () : _value(0) {
};


Fixed::~Fixed () {
};

Fixed::Fixed(const Fixed &other){
	*this = other;
};

Fixed::Fixed(const int value){
	_value = value << _frational;
};

Fixed::Fixed(const float value){
	_value = roundf(value * (1 << _frational));
};

Fixed &Fixed::operator=(const Fixed &other){
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
};

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
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

//Comparison *************************************
bool Fixed::operator>(Fixed const &fixed) const
{
	return this->_value > fixed._value;
}

bool Fixed::operator<(Fixed const &fixed) const
{
	return this->_value < fixed._value;
}

bool Fixed::operator>=(Fixed const &fixed) const
{
	return this->_value >= fixed._value;
}

bool Fixed::operator<=(Fixed const &fixed) const
{
	return this->_value <= fixed._value;
}

bool Fixed::operator==(Fixed const &fixed) const
{
	return this->_value == fixed._value;
}

bool Fixed::operator!=(Fixed const &fixed) const
{
	return this->_value != fixed._value;
}


//Static min max *************************************
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a > b ? b : a;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	return a > b ? b : a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	return a > b ? a : b;
}

//Arithmetics*****************************************
Fixed Fixed::operator+(Fixed const &fixed) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return result;
}

Fixed Fixed::operator-(Fixed const &fixed) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return result;
}

Fixed Fixed::operator*(Fixed const &fixed) const
{
	Fixed result;
	long prod = (long)this->_value * (long)fixed._value;
	result.setRawBits((int)(prod >> _frational));
	return result;
}

Fixed Fixed::operator/(Fixed const &fixed) const
{
    Fixed result;
    long num = ((long)this->_value << _frational);
    result.setRawBits((int)(num / fixed._value));
    return result;
}

//Increments | Decrements*******************************
Fixed &Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++_value;
	return temp;
}

Fixed &Fixed::operator--(void)
{
	--(_value);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return temp;
}