#include <string>
#include <sstream>
#include <exception>
#include <cctype>

int my_stoi(const std::string& text)
{
	for (std::size_t i = 0; i < text.length(); i++)
		if (!std::isdigit(text[i]))
			throw std::runtime_error("stoi failed");
	std::istringstream iss (text);
	int number;
	iss >> number;
	if (iss.fail()) {
		throw std::runtime_error("stoi failed");
	}
	return number;
}

//s == "  \n\t  " -> true
//s == " i \n\t  " -> false
bool is_only_whitespaces(const std::string& s)
{
	for (std::size_t i = 0; i < s.length(); i++)
		if (!std::isspace(s[i]))
				return false;
	return true;
}
