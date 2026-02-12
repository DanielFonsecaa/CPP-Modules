#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class Fixed{
	public:
		Fixed();                          // 1. Default constructor
		Fixed(const Fixed &other);       // 2. Copy constructor
		Fixed(const int value);
		Fixed(const float value);
		Fixed &operator=(const Fixed &ther); // 3. Copy assignment
		~Fixed();                         // 4. Destructor
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		//Comparison
		bool operator>(Fixed const &fixed) const;
		bool operator<(Fixed const &fixed) const;
		bool operator>=(Fixed const &fixed) const;
		bool operator<=(Fixed const &fixed) const;
		bool operator==(Fixed const &fixed) const;
		bool operator!=(Fixed const &fixed) const;

		//Static
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);

		//Arithmetic
		Fixed operator+(Fixed const &fixed) const;
		Fixed operator-(Fixed const &fixed) const;
		Fixed operator*(Fixed const &fixed) const;
		Fixed operator/(Fixed const &fixed) const;

		//Increments | Decrements
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

	private:
		int _value;
		static const int _frational = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);