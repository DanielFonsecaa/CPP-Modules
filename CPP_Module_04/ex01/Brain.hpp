#pragma once
#include <string>
#include <iostream>

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain const &other);
		Brain &operator=(Brain const &other);
		~Brain();
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
};
