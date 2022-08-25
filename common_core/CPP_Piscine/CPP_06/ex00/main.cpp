#include <iostream>
#include "Interpreter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Argument error" << std::endl;
		return 1;
	}
	interpreter Richard(argv[1]);

	try {
		Richard.setTrimmed(Richard.readInput());
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}

	if (Richard.getTrimmed() == "+inf" || Richard.getTrimmed() == "+inff")
	{
		std::cout	<< "char   = impossible\n"
					<< "int    = impossible\n"
					<< "float  = inff\n"
					<< "double = inf" << std::endl;
		return 0;
	}
	else if (Richard.getTrimmed() == "-inf" || Richard.getTrimmed() == "-inff")
	{
		std::cout	<< "char   = impossible\n"
					<< "int    = impossible\n"
					<< "float  = -inff\n"
					<< "double = -inf" << std::endl;
		return 0;
	}
	else if (Richard.getTrimmed() == "nanf" || Richard.getTrimmed() == "nan")
	{
		std::cout	<< "char   = impossible\n"
					<< "int    = impossible\n"
					<< "float  = nanf\n"
					<< "double = nan" << std::endl;
		return 0;
	}
	switch (Richard.getType()) {
	case 0:
		Richard.setChar(Richard.getTrimmed().c_str()[0]);
		Richard.setInt(static_cast<int>(Richard.getChar()));
		Richard.setFloat(static_cast<float>(Richard.getChar()));
		Richard.setDouble(static_cast<double>(Richard.getChar()));
		break ;
	case 1:
		Richard.setInt(std::stoi(Richard.getTrimmed()));
		Richard.setFloat(static_cast<float>(Richard.getInt()));
		Richard.setDouble(static_cast<double>(Richard.getInt()));
		Richard.setChar(static_cast<int>(Richard.getInt()));
		break ;
	case 2:
		Richard.setFloat(std::stof(Richard.getTrimmed()));
		Richard.setDouble(static_cast<double>(Richard.getFloat()));
		Richard.setInt(static_cast<int>(Richard.getFloat()));
		Richard.setChar(static_cast<char>(Richard.getFloat()));
		break ;
	case 3:
		Richard.setDouble(std::stod(Richard.getTrimmed()));
		Richard.setFloat(static_cast<float>(Richard.getDouble()));
		Richard.setInt(static_cast<int>(Richard.getDouble()));
		Richard.setChar(static_cast<char>(Richard.getDouble()));
		break ;
	}
	if (Richard.getType() >= 0)
		Richard.output();
	return 0;
}