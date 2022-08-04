#pragma once

#include "utilities.hpp"

template <class T>
std::string to_string(const T& p)
{
	std::stringstream ss;
	ss << p;
	return ss.str();
}

int my_stoi(const std::string& text);

//s == "  \n\t  " -> true
//s == " i \n\t  " -> false
bool is_only_whitespaces(const std::string& s);
