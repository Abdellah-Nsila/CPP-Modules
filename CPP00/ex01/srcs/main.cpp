/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:28:18 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/14 09:05:31 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	command;

	while (true)
	{
		command = phoneBook.input("Enter a command [ADD] [SEARCH] [EXIT]: ");
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
			break;
		else if (!command.empty())
			std::cout << "Invalid command!" << std::endl;
	}
	return (EXIT_SUCCESS);
}
