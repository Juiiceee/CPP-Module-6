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
		DIF,
		BAD
	} type;

class Scalar
{


	private:
		Scalar();
		Scalar(const Scalar &obj);
		Scalar &operator=(const Scalar &obj);
		~Scalar();
};
#endif
