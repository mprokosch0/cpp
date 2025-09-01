#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

int main (void)
{
	Base *src = generate();
	identify(NULL);
	identify(src);
	identify(*src);
	delete src;
	return 0;
}