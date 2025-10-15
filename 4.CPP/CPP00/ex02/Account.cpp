/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:19:04 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 18:57:30 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ctime>
#include "Account.hpp"

//	VARIABLES STATIQUES
int	Account::_nbAccounts         = 0;
int	Account::_totalAmount        = 0;
int	Account::_totalNbDeposits    = 0;
int	Account::_totalNbWithdrawals = 0;

//	CONSTRUCTEUR & DESTRUCTEUR
Account::Account(int initial_deposit)
{
	_accountIndex  = _nbAccounts;
	_amount        = initial_deposit;
	_nbDeposits    = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount   = _totalAmount + initial_deposit;
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
}

//	TIMESTAMP
void	Account::_displayTimestamp(void)
{
	std::time_t	now      = std::time(0);
	std::tm*	timeinfo = std::localtime(&now);

	std::cout<<"[";
	std::cout<<(timeinfo->tm_year + 1900);
	if (timeinfo->tm_mon + 1 < 10)
		std::cout<<"0";
	std::cout<<(timeinfo->tm_mon + 1);
	if (timeinfo->tm_mday < 10)
		std::cout<<"0";
	std::cout<<(timeinfo->tm_mday);
	std::cout<<"_";
	if (timeinfo->tm_hour < 10)
		std::cout<<"0";
	std::cout<<(timeinfo->tm_hour);
	if (timeinfo->tm_min < 10)
		std::cout<<"0";
	std::cout<<(timeinfo->tm_min);
	if (timeinfo->tm_sec < 10)
		std::cout<<"0";
	std::cout<<(timeinfo->tm_sec);
	std::cout<<"]";
}

//	GETTERS
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

//	DISPLAY
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout<<" index;"<<_accountIndex;
	std::cout<<";amount:"<<_amount;
	std::cout<<";deposits:"<<_nbDeposits;
	std::cout<<";withdrawals:"<<_nbWithdrawals;
	std::cout<<std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout<<" accounts:"<<_nbAccounts;
	std::cout<<";total:"<<_totalAmount;
	std::cout<<";deposits:"<<_totalNbDeposits;
	std::cout<<";withdrawals:"<<_totalNbWithdrawals;
	std::cout<<std::endl;
}

//	OPERATIONS
void	Account::makeDeposit(int deposit)
{
	int	p_amount = _amount;

	_amount = _amount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount = _totalAmount + deposit;
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex;
	std::cout<<";p_amount:"<<p_amount;
	std::cout<<";deposit:"<<deposit;
	std::cout<<";amount:"<<_amount;
	std::cout<<";nb_deposits:"<<_nbDeposits;
	std::cout<<std::endl;
}


bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount = _amount;

	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout<<" index:"<<_accountIndex;
		std::cout<<";p_amount:"<<p_amount;
		std::cout<<";withdrawal:refused";
		std::cout<<std::endl;
		return (false);
	}
	_amount = _amount - withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount = _totalAmount - withdrawal;
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex;
	std::cout<<";p_amount:"<<p_amount;
	std::cout<<";withdrawal:"<<withdrawal;
	std::cout<<";amount:"<<_amount;
	std::cout<<";nb_withdrawals:"<<_nbWithdrawals;
	std::cout<<std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}
