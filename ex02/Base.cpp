#include "Base.hpp"

Base *generate(void)
{
	int nbr = std::rand() % 3;
	switch (nbr)
	{
	case 0:
		return (new A);
		break;
	case 1:
		return (new B);
		break;
	case 2:
		return (new C);
		break;
	default:
		return (NULL);
		break;
	}
	return (NULL);
}

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "C'est une classe de type A " << a << std::endl;
		return ;
	}
	B *b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "C'est une classe de type B " << b << std::endl;
		return ;
	}
	C *c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "C'est une classe de type C " << c << std::endl;
		return ;
	}
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "C'est une classe de type A " << &a << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "C'est une classe de type B " << &b << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C'est une classe de type C " << &c << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
}
