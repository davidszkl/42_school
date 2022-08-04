#include <iostream>
#include "phonebook.hpp"
#include "contact.hpp"

std::string str_toupper(std::string str)
{
	for (size_t n = 0; n < str.length(); n++)
		str[n] = std::toupper(str[n]);
	return (str);
}

int main()
{
	std::string	input;
	phonebook	phonebook;

	std::cout << "Welcome to the PhoneBook !\n\n";
	phonebook.setnbr(0);
	while (1)
	{
		std::cout << "What would you like to do?\n";
		getline(std::cin, input);
		input = str_toupper(input);
		if (input == "EXIT")
		{
			std::cout << "Closing the phonebook will lose your contacts forever, ever.\nDo you want to continue ? (yes / no)\n";
			while (1)
			{
				std::cin >> input;
				if (input == "yes")
					return (0);
				if (input == "no")
					break ;
				else
					std::cout << "type 'yes' or 'no'.\n";
			}
		}
		else if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else
			std::cout << "Unknown command, try add / search / exit" << std::endl;
	}
	return 0;
}