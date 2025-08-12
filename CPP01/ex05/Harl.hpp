/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:14:43 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/12 10:58:17 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef HARL_H_
# define HARL_H_

# include "string"

# define RESET   "\033[1m\033[0m"
# define RED     "\033[1m\033[31m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"

class	Harl
{
private:
	
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
