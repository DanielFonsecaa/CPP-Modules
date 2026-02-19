#include "Rpn.hpp"

Rpn::Rpn() {}
Rpn::~Rpn() {}
Rpn::Rpn(const Rpn& other) { (void)other; }
Rpn& Rpn::operator=(const Rpn& other) 
{ 
	(void)other; 
	return *this; 
}

bool isOperator(char c){
	return (c == '+' || c == '-' || c == '*' || c == '/');
};

int Rpn::execute(const std::string& expression){
	std::istringstream iss(expression);
	std::string token;
	std::stack<int> stack;
	while (iss >> token)
	{
		if (token.length() != 1)
			throw std::runtime_error("Error");
		char c = token[0];
		if (isdigit(c))
			stack.push(c - '0');
		else if (isOperator(c)){
			if (stack.size() < 2)
				throw std::runtime_error("Error");
			int num = stack.top();
			stack.pop();
			int num2 = stack.top();
			stack.pop();
			int result;
			switch (c)
			{
			case '+':
				result = num2 + num;
				break;
			case '-':
				result = num2 - num;
				break;
			case '*':
				result = num2 * num;
				break;
			default:
				if (num == 0)
					throw std::runtime_error("Error");
				result = num2 / num;
				break;
			}
			stack.push(result);
		}
		else
			throw std::runtime_error("Error");
	}
	if (stack.size() != 1)
			throw std::runtime_error("Error");
	return stack.top();
};