/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:21:04 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/14 10:19:02 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

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
		std::string	input(std::string msg);
		bool		add();
		void		getContactById();
		void		search();
};

#endif
