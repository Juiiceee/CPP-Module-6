#include "Scalar.hpp"

Scalar::Scalar()
{
	std::cout << "Scalar default constructor called\n";
}

Scalar::Scalar(const Scalar &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Scalar &Scalar::operator=(const Scalar &obj)
{
	std::cout << "Copy assignment operator called\n";
	return *this;
}

Scalar::~Scalar()
{
	std::cout << "Destructor of Scalar called\n";
}

bool isChar(const std::string &str)
{
	return (str.size() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]));
}

bool isDoub(const std::string &str)
{
	char *endptr = NULL;
	double nbr = std::strtod(str.c_str(), &endptr);
	if (*endptr == '\0')
	{
		if (nbr == -HUGE_VAL || nbr == HUGE_VAL)
			return (0);
		int length = str.find('.');
		if (length == str.size() - 2 && length != std::string::npos)
			return (1);
	}
	return (0);
}

bool isFloat(const std::string &str)
{
	char *endptr = NULL;
	float nbr = std::strtof(str.c_str(), &endptr);
	if (*endptr == '\0')
	{
		if (nbr == -HUGE_VALF || nbr == HUGE_VALF)
			return (0);
		int length = str.find('.');
		if (length == str.size() - 3 && length != std::string::npos)
			return (1);
	}
	return (0);
}

bool isInt(const std::string &str)
{
	char *endptr = NULL;
	long nbr = std::strtol(str.c_str(), &endptr, 10);
	if (*endptr == '\0' && (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max() || nbr == HUGE_VALF))
		return (1);
	return (0);
}

type checkType(const std::string &str)
{
	if (isChar(str))
		return (CHAR);
	if (isInt(str))
		return (INT);
	if (isDoub(str))
		return (DOUB);
	if (isFloat(str))
		return (FLO);
	return (BAD);
}
