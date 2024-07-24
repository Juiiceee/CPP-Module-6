#ifndef SCALAR_HPP
# define SCALAR_HPP
# include <iostream>
# include <string>

class Scalar
{
	public:
		Scalar();
		Scalar(const Scalar &obj);
		Scalar &operator=(const Scalar &obj);
		~Scalar();
	typedef enum type
	{
		Char,
		Int,
		Float,
		Double
	} type;
};
#endif
