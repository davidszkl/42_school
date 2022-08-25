#include "Karen.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Argument error" << std::endl;
		return 1;
	}
	Karen	Karen;
	
	int n = 0;
	if ((std::string)argv[1] == "DEBUG")
		n = 1;
	else if ((std::string)argv[1] == "INFO")
		n = 2;
	else if ((std::string)argv[1] == "WARNING")
		n = 3;
	else if ((std::string)argv[1] == "ERROR")
		n = 4;
	switch (n)
	{
		case 1:
			Karen.complain("debug");
			Karen.complain("info");
			Karen.complain("warning");
			Karen.complain("error");
			break ;
		case 2:
			Karen.complain("info");
			Karen.complain("warning");
			Karen.complain("error");
			break ;
		case 3:
			Karen.complain("warning");
			Karen.complain("error");
			break ;
		case 4:
			Karen.complain("error");
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}