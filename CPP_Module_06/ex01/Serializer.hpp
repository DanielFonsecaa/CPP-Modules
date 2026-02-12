#pragma once
#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();
		Serializer &operator=(const Serializer &src);
	public:
		// converts ptr to int
		static uintptr_t serialize(Data* ptr);
		// converts int to ptr (memory addres)
		static Data* deserialize(uintptr_t raw);
};