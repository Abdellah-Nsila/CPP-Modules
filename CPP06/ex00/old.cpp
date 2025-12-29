

// void	display(std::string s, int c, long n_int, float n_float, double n_double)
// {
// 	// Char
// 	if (isPseudoLiterals(s) || isOutOfRange<long, int>(n_int) || isOutOfRange<int, char>(n_int))
// 		std::cout << "char: impossible" << std::endl;
// 	else if ((c < 32 || c > 126))
// 		std::cout << "char: Non displayable" << std::endl;
// 	else
// 		std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;

// 	// Int
// 	if (isPseudoLiterals(s) || isOutOfRange<long, int>(n_int))
// 		std::cout << "int: impossible" << std::endl;
// 	else
// 		std::cout << "int: " << static_cast<int>(n_int) << std::endl;

// 	std::cout << std::fixed << std::setprecision(1);
// 	// Float
// 	if (isPseudoLiterals(s))
// 		std::cout << "float: "  << n_float << "f" << std::endl;
// 	else if (isOutOfRange<float, float>(n_float))
// 		std::cout << "float: impossible" << std::endl;
// 	else
// 		std::cout << "float: "  << n_float << "f" << std::endl;

// 	// Double
// 	if (isPseudoLiterals(s))
// 		std::cout << "double: "  << n_double << std::endl;
// 	else if (isOutOfRange<double, double>(n_double))
// 		std::cout << "double: impossible" << std::endl;
// 	else
// 		std::cout << "double: " << n_double << std::endl;
// }


// void	castToTypes(std::string s)
// {
// 	int		c = 0;
// 	long	n_int = 0;
// 	float	n_float = 0.0f;
// 	double	n_double = 0.0;

// 	switch (getType(s))
// 	{
// 		case (CHAR):
// 		{
// 			c = s[0];
// 			n_int = static_cast<long>(c);
// 			n_float = static_cast<float>(c);
// 			n_double = static_cast<double>(c);
// 			break ;
// 		}
// 		case  (INT):
// 		{
// 			n_int = atol(s.c_str());
// 			c = static_cast<char>(n_int);
// 			n_float = static_cast<float>(n_int);
// 			n_double = static_cast<double>(n_int);
// 			break;
// 		}
// 		case (FLOAT):
// 		{
// 			n_float = strtof(s.c_str(), NULL);
// 			c = static_cast<char>(n_float);
// 			n_int = static_cast<long>(n_float);
// 			n_double = static_cast<double>(n_float);
// 			break;
// 		}
// 		case  (DOUBLE):
// 		{
// 			n_double = strtod(s.c_str(), NULL);
// 			c = static_cast<char>(n_double);
// 			n_int = static_cast<long>(n_double);
// 			n_float = static_cast<float>(n_double);
// 			break ;
// 		}
// 		default:
// 			std::cerr << "Error: Impossible" << std::endl;
// 			return ;
// 	}
// 	display(s, c, n_int, n_float, n_double);
// }