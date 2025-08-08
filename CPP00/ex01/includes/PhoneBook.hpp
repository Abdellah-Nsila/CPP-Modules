/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:21:04 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/08 18:03:01 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "includes.hpp"
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact arr[MAX];
		int		index;
		int		total;
	public:
		PhoneBook();
		string	input(string msg);
		bool	add();
		void	getContactById();
		void	search();

};

#endif
