/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:07:45 by jduval            #+#    #+#             */
/*   Updated: 2023/07/24 17:04:08 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

Account::Account(void)
{
	_accountIndex = getNbAccounts();
	_nbAccounts += 1;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex << ";"
				<< "amount:" << "0" << ";"
				<< "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< " accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t		raw_time;
	struct tm	*local_time;
	char		output[18];

	time(&raw_time);
	local_time = localtime(&raw_time);
	strftime(output, 18, "[%Y%m%d_%H%M%S]", local_time);
	std::cout << output;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex << ";"
				<< "amount:" << checkAmount() << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawals)
{
	if (_amount - withdrawals < 0)
	{
		_displayTimestamp();
		std::cout	<< " index:" << _accountIndex << ";"
					<< "p_amount:" << _amount << ";"
					<< "withdrawal:refused" << std::endl;
		return (false);
	}
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";
	_amount -= withdrawals;
	_totalAmount -= withdrawals;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout	<< "withdrawal:" << withdrawals << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout	<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits
				<< std::endl;
}
