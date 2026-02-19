#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <exception>

class Rpn
{
	public:
		Rpn();
		~Rpn();
		Rpn(const Rpn& other);
		Rpn& operator=(const Rpn& other);
		int execute(const std::string& expression);
	};