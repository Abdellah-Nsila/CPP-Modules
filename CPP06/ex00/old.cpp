bool	isFloat(std::string s)
{
	char*	endPtr;

	strtof(s.c_str(), &endPtr);
	if (*endPtr == 'f' && *(endPtr + 1) == '\0')
	{
		if (s.find(".", 1) != std::string::npos)
			return (true);
	}
	std::cout << "Not double: " << "\"" << endPtr << "\"" << std::endl;
	return (false);

	// std::string	rest;
	// rest = endPtr;
	// if (*endPtr == '\0' // Need remaining to check if it is "f" at the end
	// 	|| rest != "f" // If it dosen't contain 'f' at the end
	// 	|| s.find('.', 1) == std::string::npos // If it begin with '.'
	// 	|| s.find(".f", 1) != std::string::npos) // If it contain ".f"
	// {
	// 	std::cout << "Not float: " << "\"" << endPtr << "\"" << std::endl;
	// 	return (false);
	// }
	// return (true);
}

bool	isDouble(std::string s)
{
	char*	endPtr;

	strtod(s.c_str(), &endPtr);
	if (*endPtr == '\0')
	{
		if (s.find('.', 1) != std::string::npos && s[s.length() - 1] != '.')
			return (true);
	}
	std::cout << "Not double: " << "\"" << endPtr << "\"" << std::endl;
	return (false);

	// const char*	str;
	// str = s.c_str();
	// std::string	rest;
	// rest = endPtr;
	// if (*endPtr != '\0' // Contain non valid content
	// 	|| (s[s.length() - 1] == '.') // If it contain '.' at the end
	// 	|| s.find('.', 1) == std::string::npos // If it begin with '.'
	// 	)
	// {
	// 	std::cout << "Not double: " << "\"" << endPtr << "\"" << std::endl;
	// 	return (false);
	// }
	// return (true);
}