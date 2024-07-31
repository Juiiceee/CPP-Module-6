#include "Scalar.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string str = std::string(argv[1]);
		if (str.empty())
			return (error(str), 1);
		Scalar::convert(str);
		return (0);
	}
	std::cout << "Bad input\n";
	return (1);
}