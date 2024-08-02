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
	(void)obj;
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
	double nbr = strtod(str.c_str(), &endptr);
	if (*endptr == '\0')
	{
		if (nbr == -HUGE_VAL || nbr == HUGE_VAL)
			return (0);
		size_t length = str.find('.');
		if (length == str.size() - 2 && length != std::string::npos)
			return (1);
	}
	return (0);
}

bool isFloat(const std::string &str)
{
	char *endptr = NULL;
	float nbr = strtof(str.c_str(), &endptr);
	if (*endptr == 'f' && endptr == &str[str.size() - 1])
	{
		if (nbr == -HUGE_VALF || nbr == HUGE_VALF)
			return (0);
		std::string feuille = str.substr(0, endptr - str.c_str());
		size_t length = feuille.find('.');
		if (length != std::string::npos && length == str.size() - 3)
			return (1);
	}
	return (0);
}

bool isInt(const std::string &str)
{
	char *endptr = NULL;
	long nbr = strtol(str.c_str(), &endptr, 10);
	if (*endptr == '\0')
	{
		if ((nbr == LONG_MAX || nbr == LONG_MIN) || (nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min()))
			return (0);
		return (1);
	}
	return (0);
}

bool isDif(const std::string &str)
{
	return (str == "nan" || str == "nanf" || str == "-inff" || str == "-inf" || str == "inff" || str == "inf");
}

void	printChar(char c)
{
	std::cout << "Char: '" << c << "'" << std::endl;
}

void	printInt(int nb)
{
	std::cout << "Int: " << nb << std::endl;
}

void	printDouble(double nb)
{
	std::cout << "Double: " << nb << std::endl;
}

void	printFloat(float nb)
{
	std::cout << std::fixed << std::setprecision(1) <<"Float: " << nb << "f" << std::endl;
}

void	Char(std::string str)
{
	char c = str[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void	Int(std::string str)
{
	int	nb = atoi(str.c_str());
	if (nb >= 32 && nb <= 126)
		printChar(static_cast<char>(nb));
	else
		std::cout << "Char: Unpritable Char\n";
	printInt(static_cast<int>(nb));
	printFloat(static_cast<float>(nb));
	printDouble(static_cast<double>(nb));
}

void	Float(std::string str)
{
	float	nbf = atof(str.c_str());
	int		nb = roundf(nbf);
	long	nbl = atol(str.c_str());
	if (nb >= 32 && nb <= 126)
		printChar(static_cast<char>(nb));
	else
		std::cout << "Char: Unpritable Char\n";
	if ((nbl == LONG_MAX || nbl == LONG_MIN) || (nbl > std::numeric_limits<int>::max() || nbl < std::numeric_limits<int>::min()))
		std::cout << "Int: Unpritable Int\n";
	else
		printInt(static_cast<int>(nbf));
	printFloat(static_cast<float>(nbf));
	printDouble(static_cast<double>(nbf));
}

void	Double(std::string str)
{
	float	nbf = atof(str.c_str());
	int		nb = roundf(nbf);
	long	nbl = atol(str.c_str());
	double nbd = strtod(str.c_str(), NULL);
	if (nb >= 32 && nb <= 126)
		printChar(static_cast<char>(nb));
	else
		std::cout << "Char: Unpritable Char\n";
	if ((nbl == LONG_MAX || nbl == LONG_MIN) || (nbl > std::numeric_limits<int>::max() || nbl < std::numeric_limits<int>::min()))
		std::cout << "Int: Unpritable Int\n";
	else
		printInt(static_cast<int>(nbd));
	printFloat(static_cast<float>(nbd));
	printDouble(static_cast<double>(nbf));
}

void	printDif(std::string str)
{
	std::cout << "Char: Unpritable Char\n";
	std::cout << "Int: Unpritable Int\n";
	if (str == "nan" || str == "nanf")
	{
		std::cout << "Float: nanf\n";
		std::cout << "Double: nan\n";
	}
	else if (str == "-inff" || str == "-inf")
	{
		std::cout << "Float: -inff\n";
		std::cout << "Double: -inf\n";
	}
	else
	{
		std::cout << "Float: inff\n";
		std::cout << "Double: inf\n";
	}
}

type checkType(const std::string &str)
{
	if (isChar(str))
		return (CHAR);
	if (isInt(str))
		return (INT);
	if (isFloat(str))
		return (FLO);
	if (isDoub(str))
		return (DOUB);
	if (isDif(str))
		return (DIF);
	return (BAD);
}

void	error(std::string &str)
{
	std::cout << "Bad input: '" << str << "'\n";
}

void Scalar::convert(const std::string &str)
{
	type type = checkType(str);

	switch (type)
	{
		case CHAR:
			Char(str);
			break;
		case INT:
			Int(str);
			break;
		case FLO:
			Float(str);
			break;
		case DOUB:
			Double(str);
			break;
		case DIF:
			printDif(str);
			break;
		case BAD:
			std::cout << "No input looks like a type\n";
			break;
	}
}
