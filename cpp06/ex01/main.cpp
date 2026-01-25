#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "Daniel";
	data.value = 3.14;

	Data* original = &data;

	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original pointer:   " << original << std::endl;
	std::cout << "Serialized (raw):   " << raw << std::endl;
	std::cout << "Restored pointer:   " << restored << std::endl;

	if (restored == original)
		std::cout << "OK: pointers are equal" << std::endl;
	else
		std::cout << "ERROR: pointers are different" << std::endl;

	// Extra proof: the data is the same object
	std::cout << "Restored->id:    " << restored->id << std::endl;
	std::cout << "Restored->name:  " << restored->name << std::endl;
	std::cout << "Restored->value: " << restored->value << std::endl;

	return 0;
}