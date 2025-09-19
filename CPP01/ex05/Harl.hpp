/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:14:43 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 15:31:37 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HARL_HPP
# define HARL_HPP

# include "string"
# include "iostream"

# define RESET   "\033[0m"
# define BOLDRED     "\033[1m\033[31m"
# define BOLDYELLOW  "\033[1m\033[33m"
# define BOLDBLUE    "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"

class	Harl
{
	public:
		Harl();
		~Harl();
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	complain( std::string level );
};

#endif
