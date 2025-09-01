
#include "../includes/iter.hpp"


void printStr(char const &str)
{
	 std::cout << str << std::endl;
}

void printInt(int const &nb)
{
	 std::cout << nb << std::endl;
}
int main()
{
    int tab[] = {0, 1, 2, 3, 4};
	char str[] = "bonjour !!";
    ::iter(tab, 5, printInt);
    ::iter(str, 10, printStr);

    return 0;
}