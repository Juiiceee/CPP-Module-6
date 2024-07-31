#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called\n";
}

Serializer::Serializer(const Serializer &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Serializer &Serializer::operator=(const Serializer &obj)
{
	std::cout << "Copy assignment operator called\n";
	(void)obj;
	return *this;
}

Serializer::~Serializer()
{
	std::cout << "Destructor of Serializer called\n";
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}