#ifndef SCALAR_HPP
# define SCALAR_HPP
# include <iostream>
# include <string>
#include <cmath>
#include <climits>
#include <limits>

	typedef enum type
	{
		CHAR,
		INT,
		FLO,
		DOUB,
		BAD
	} type;

class Scalar
{
	public:
		static void convert(const std::string &str);
	private:
		Scalar();
		Scalar(const Scalar &obj);
		Scalar &operator=(const Scalar &obj);
		~Scalar();
};
void	error(std::string &str);
#endif
