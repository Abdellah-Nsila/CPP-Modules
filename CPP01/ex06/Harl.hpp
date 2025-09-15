/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:14:43 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 11:55:39 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HARL_H_
# define HARL_H_

# include "string"
# include "iostream"

# define RESET   "\033[0m"
# define BOLDRED     "\033[1m\033[31m"
# define BOLDYELLOW  "\033[1m\033[33m"
# define BOLDBLUE    "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDWHITE   "\033[1m\033[37m"

enum	e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
};

class	Harl
{		
	public:
		Harl();
		~Harl();
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	other( void );
		void	complain( std::string level );
		int		getEnumLevel(std::string level);
};

#endif
