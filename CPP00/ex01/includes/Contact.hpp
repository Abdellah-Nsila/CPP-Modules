/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:18:53 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/14 10:19:59 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "includes.hpp"

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
		
	public:
		Contact ( void );
		Contact ( std::string firstName, std::string lastName, std::string nickName
				, std::string phoneNumber, std::string darkestSecret );
		std::string	formatString( std::string str );
		void		displayField( std::string field );
		void		displayColumn( int id );
		void		displayContact( void );
};

# endif
