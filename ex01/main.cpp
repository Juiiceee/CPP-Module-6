#include "Serializer.hpp"

int main()
{
	Data da;
	da.nombre = 15;
	da.str = "feuille";

	uintptr_t ptr;

	ptr = Serializer::serialize(&da);


	std::cout << "ptr serialize data: " << ptr << std::endl;

	Data *dada = Serializer::deserialize(ptr);

	std::cout << "nombre deserialize: " << dada->nombre << std::endl;
	std::cout << "str deserialize: " << dada->str << std::endl;

	if (&da == dada)
		std::cout << "IS GOOD\n";
	else
		std::cout << "NOT GOOD\n";
}