#include <iostream>

int main(int argc, char **argv)
{
	int	n;
	int	j;

	n = 0;
	(void)argc;
	if (!argv[1])
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[++n])
	{
		j = 0;
		while (argv[n][j])
			std::cout << (char)toupper(argv[n][j++]);
	}
	std::cout << std::endl;
	return (0);
}