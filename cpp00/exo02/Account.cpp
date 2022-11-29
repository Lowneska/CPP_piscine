/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:50:13 by skhali            #+#    #+#             */
/*   Updated: 2022/11/29 15:24:56 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts++;
	this->_totalAmount = _totalAmount + initial_deposit;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    _displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";" << "amount:"
    << this->_amount << ";" << "created" << std::endl;
}

Account::Account()
{
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    _displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";" << "amount:"
    << this->_amount << ";" << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	this->_nbAccounts--;
	std::cout << " index:" << _accountIndex << ";" << "amount:"
    << _amount << ";" << "closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}
//mettre les 0
void Account::_displayTimestamp( void )
{
    std::tm nowLocal;
    std::time_t now;

    now = time(NULL);
    nowLocal = *localtime(&now);
    std::cout << "[" << nowLocal.tm_year + 1900
	<< nowLocal.tm_mon + 1 << nowLocal.tm_mday << "_"
	<< nowLocal.tm_hour << nowLocal.tm_min << nowLocal.tm_sec
	<< "]";
}

//chercher why le const
int		Account::checkAmount(void) const
{
    return this->_amount;
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";" << "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";"
	<< "total:" << Account::getTotalAmount() << ";" << "deposits:"
	<< Account::getNbDeposits() << ";" << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount << ";" << "withdrawal:";
	if (withdrawal > this->_amount)
		return ( std::cout << "refused" << std::endl, false);
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		std::cout << withdrawal << ";" << "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount << ";" << "deposit:";
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	std::cout << deposit << ";" << "amount:" << this->_amount << ";"
	<< "nb_withdrawals:" << this->_nbDeposits << std::endl;
}
