/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:18:53 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/08 19:25:10 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_H
# define CONTACT_H

# include "includes.hpp"

class	Contact
{
	private:
		string	firstName;
		string	lastName;
		string	nickName;
		string	phoneNumber;
		string	darkestSecret;
		
	public:
		
		Contact ( void );
		Contact ( string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret );
		string	formatString( string str );
		void	displayField( string field );
		void	displayColumn( int id );
		void	displayContact( void );
};

# endif
