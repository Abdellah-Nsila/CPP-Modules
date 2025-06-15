/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:28:18 by abnsila           #+#    #+#             */
/*   Updated: 2025/06/15 19:22:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

using namespace std;

int	main()
{
	PhoneBook	phoneBook;
	string		command;

	while (true)
	{
		command = phoneBook.input("Enter a command [ADD] [SEARCH] [EXIT]: ");
		if (command.empty())
		{
			cout << "\nEOF detected. Exiting.\n" << endl;
			break;
		}
		else if (command == "ADD")
		{
			if (!phoneBook.add())
				cout << "\nError in adding Contact!" << endl;
		}
		else if (command == "SEARCH")
		{
			phoneBook.search();
		}
		else if (command == "EXIT")
			break ;
		else
			cout << "Invalid command!\n";
	}
	return (0);
}
