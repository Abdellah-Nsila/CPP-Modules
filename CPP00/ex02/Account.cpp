/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:00:31 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/09 12:54:25 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <iomanip>
# include <ctime>

// Init shared members
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constuctor
Account::Account( int initial_deposit )
{
	// Account instance index
	this->_accountIndex = getNbAccounts();
	// Incerement nuber of account by 1
	_nbAccounts++;
	// Init depo fot this account instance
	this->_amount = initial_deposit;
	// Accumulate total amount by each amount instance
	_totalAmount += initial_deposit;
	// Init local and shared deposits members
	this->_nbDeposits = 0;
	_totalNbDeposits = 0;
	// Timestamp and info log for this account instance
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "created" << std::endl;
}

// Destructor
Account::~Account()
{
	// Timestamp and info log for this account instance
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "closed" << std::endl;
}

// ------------------------------------ First Methods -------------------------------
int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	// Timestamp and info log for this account instance
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals()
			<< std::endl;
}

// ------------------------------------ Second Methods -------------------------------
void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	
	// Timestamp and info log for this account instance
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << (this->_amount - deposit) << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_deposits:" << this->_nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (checkAmount() - withdrawal < 0)
	{
		// Timestamp and info log for this account instance
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "withdrawal:" << "refused"
			<< std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	// Timestamp and info log for this account instance
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << (this->_amount + withdrawal) << ";"
			<< "withdrawal:" << withdrawal << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	return (true);
}

int	Account::checkAmount() const
{
	return (this->_amount);
}

void	Account::displayStatus() const
{
	// Timestamp and info log for this account instance
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t		now = time(NULL);
	struct tm	*current_time = localtime(&now);

	std::cout << "[" 
			<< 1900 + current_time->tm_year 
			<< std::setfill('0') << std::setw(2) << current_time->tm_mon + 1
			<< std::setfill('0') << std::setw(2) << current_time->tm_mday
			<< "_"
			<< std::setfill('0') << std::setw(2) << current_time->tm_hour
			<< std::setfill('0') << std::setw(2) << current_time->tm_min
			<< std::setfill('0') << std::setw(2) << current_time->tm_sec
			<< "]"
			<< " ";
}
