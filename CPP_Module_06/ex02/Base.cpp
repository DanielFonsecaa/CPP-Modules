#include "Base.hpp"

Base::~Base() {}

Base* Base::generate(void) {
	int r = std::rand() % 3;
	switch (r)
	{
		case 0: return new A();
		case 1: return new B();
		default: return new C();
	}
}

//this with ptr can be NULL and it will fail with NULL.
void Base::identify(Base* p) {
	if (!p)
	{
		std::cout << "Null pointer (ptr)\n";
		return;
	}
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A\n";
		return;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "B\n";
		return;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C\n";
		return;
	}
	std::cout << "Unknown (ptr)\n";
}

//this with reference will never be NULL and it will fail with exception.
void Base::identify(Base& p) {
	try
	{
		(void)dynamic_cast<A&>(p); std::cout << "A\n";
		return;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p); std::cout << "B\n";
		return;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p); std::cout << "C\n";
		return;
	}
	catch (...) {}
	std::cout << "Unknown (ref)\n";
}