#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

class Fixed{
	public:
		Fixed();                          // 1. Default constructor
		Fixed(const Fixed &other);       // 2. Copy constructor
		Fixed &operator=(const Fixed &ther); // 3. Copy assignment
		~Fixed();                         // 4. Destructor
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _value;
		static const int _frational = 8;
};