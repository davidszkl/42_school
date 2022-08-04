#include <iostream>

int main()
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "address =     "	<< &string << std::endl;
	std::cout << "ptr address = "	<< stringPTR << std::endl;
	std::cout << "ref address = "	<< &stringREF << std::endl;
	std::cout << "\n";

	std::cout << *stringPTR	<< "\n";
	std::cout << stringREF	<< "\n";
	std::cout << string		<< std::endl;
	return (0);
}