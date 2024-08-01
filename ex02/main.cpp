#include <iostream>
#include "Base.hpp"

int main()
{
	std::srand(std::time(0));
	Base *A = generate();
	identify(A);
	identify(*A);
	Base *B = generate();
	identify(B);
	identify(*B);
	Base *C = generate();
	identify(C);
	identify(*C);
	Base *D = generate();
	identify(D);
	identify(*D);
	Base *E = generate();
	identify(E);
	identify(*E);
	Base *F = generate();
	identify(F);
	identify(*F);
	Base *G = generate();
	identify(G);
	identify(*G);
	Base *H = generate();
	identify(H);
	identify(*H);
	Base *I = generate();
	identify(I);
	identify(*I);
	Base *J = generate();
	identify(J);
	identify(*J);
	Base *K = generate();
	identify(K);
	identify(*K);
}