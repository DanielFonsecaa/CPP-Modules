#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"	
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << "----------First Test-----------" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "----------Second Test-----------" << std::endl;
		std::cout << "----------Wrong Animal----------" << std::endl;
		const WrongAnimal* wronganimal = new WrongAnimal();
		const WrongAnimal* wrongcat = new WrongCat();
		std::cout << wrongcat->getType() << " " << std::endl;
		wronganimal->makeSound();
		wrongcat->makeSound();

		delete wronganimal;
		delete wrongcat;
	}
	return 0;
}