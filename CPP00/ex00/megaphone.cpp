#include <iostream>

void	strToUpper(char* s)
{
	int	i;

	i = 0;
	for (int i = 0; s[i]; i++)
		s[i] = std::toupper(s[i]);
}

int	main(int argc, char* argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (-1);
	}
	while (i < argc)
	{
		strToUpper(argv[i]);
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;
	return (0);
}
