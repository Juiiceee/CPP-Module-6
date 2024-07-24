#include "Scalar.hpp"

Scalar::Scalar()
{
	std::cout << "Scalar default constructor called\n";
}

Scalar::Scalar(const Scalar &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
	return ;
}

Scalar &Scalar::operator=(const Scalar &obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
	{
		
	}
	return *this;
}

Scalar::~Scalar()
{
	std::cout << "Destructor of Scalar called\n";
}


