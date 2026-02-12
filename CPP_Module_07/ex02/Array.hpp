#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

class ArrayNullException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Array is empty";
		}
};

template <typename T> class Array
{
	private:
		T*              _array;
		unsigned int    _size;
	public:
		Array() : _array(NULL), _size(0)
		{
			std::cout << "Default Array Template constructor called" << std::endl;
		}

		Array(unsigned int val)
		{
			_array = (val > 0) ? new T[val] : NULL;
			_size = val;
			std::cout << "Parameterized constructor called" << std::endl;
		}

		Array(const Array &other) : _size(other._size)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
			std::cout << "Copy constructor called" << std::endl;
		}

		~Array()
		{
			delete[] _array;
			std::cout << "Destructor called" << std::endl;
		}

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] _array;
				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			std::cout << "Assignment operator called" << std::endl;
			return *this;
		}
 
		T &operator[](size_t index)
		{
			if (_size == 0)
				throw ArrayNullException();
			if (index >= _size)
				throw std::out_of_range("Index is out of range");
			return (_array[index]);
		}
		
		const T &operator[](size_t index) const
		{
			if (_size == 0)
				throw ArrayNullException();
			if (index >= _size)
				throw std::out_of_range("Index is out of range");
			return (_array[index]);
		}

		unsigned int size() const
		{
			return (this->_size);
		}
};