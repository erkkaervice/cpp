/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:49:09 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/13 12:48:29 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::time_t	t = std::time(0);
	std::tm*	now = std::localtime(&t);

	std::cout << "[" << (now->tm_year + 1900)
			<< std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
			<< std::setfill('0') << std::setw(2) << now->tm_mday
			<< "_"
			<< std::setfill('0') << std::setw(2) << now->tm_hour
			<< std::setfill('0') << std::setw(2) << now->tm_min
			<< std::setfill('0') << std::setw(2) << now->tm_sec
			<< "] ";
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";deposit:" << deposit;

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout << ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:";

	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}

	std::cout << withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	std::cout << ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
