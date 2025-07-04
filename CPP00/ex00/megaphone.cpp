# include <iostream>
# include <string>

using namespace std;

char	upperCase(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

void	strToUpper(char** s)
{
	int	i;

	i = 0;
	while ((*s)[i])
	{
		(*s)[i] = upperCase((*s)[i]);
		i++;
	}
}

int	main(int argc, char* argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (-1);
	}
	while (i < argc)
	{
		strToUpper(&argv[i]);
		cout << argv[i] << " ";
		i++;
	}
	cout << endl;
	return (0);
}
