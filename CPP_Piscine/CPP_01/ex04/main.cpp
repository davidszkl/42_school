#include <fstream>
#include <iostream>

int main(int argc, char**argv)
{
	if (argc != 4 || !argv[2][0] || !argv[3][0])
	{
		std::cout << "Argument error\n";
		return (1);
	}
	std::ifstream ifs;
	ifs.open(argv[1], std::ifstream::in);

	std::string outName = std::string(argv[1] + std::string(".replace"));

	std::ofstream ofs(outName);
	std::string temp;
	while (ifs >> temp)
	{
		if (temp == std::string(argv[2]))
			ofs << std::string(argv[3]) << " ";
		else
			ofs << temp << " ";
	}
	ofs << std::endl;
	ifs.close();
	return (0);
}