/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:18:53 by abnsila           #+#    #+#             */
/*   Updated: 2025/06/15 19:24:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_H
# define CONTACT_H

# include "includes.hpp"

using namespace std;

class	Contact
{
	private:
		string	firstName;
		string	lastName;
		string	nickName;
		string	phoneNumber;
		string	darkestSecret;
	public:
		Contact ();
		Contact (string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret);
		void	displayColumn(int id);
		void	displayContact(void);
};

# endif
