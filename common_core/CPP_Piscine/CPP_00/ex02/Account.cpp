#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex	= _nbAccounts;
	_amount			= initial_deposit;
	_nbDeposits		= 0;
	_nbWithdrawals	= 0;
	_nbAccounts		+= 1;
	_totalAmount	+= initial_deposit;
	t::_displayTimestamp();
	std::cout	<< "index:"		<< _accountIndex	<< ";"
				<< "amount:"	<< _amount 		<< ";"
				<< "created"	<< std::endl;
}

Account::~Account()
{
	t::_displayTimestamp();
	std::cout	<< "index:"		<< _accountIndex	<< ";"
				<< "amount:"	<< _amount 		<< ";"
				<< "closed"		<< std::endl;
	_nbAccounts -= 1;
}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void	Account::makeDeposit(int deposit)
{
	t::_displayTimestamp();
	std::cout	<< "index:"		<< _accountIndex	<< ";"
				<< "p_amount:"	<< _amount 			<< ";"
				<< "deposit:"	<< deposit			<< ";";
	this->_amount		+= deposit;
	this->_nbDeposits	+= 1;
	_totalAmount		+= deposit;
	_totalNbDeposits	+= 1;
	std::cout	<< "amount:"		<< _amount		<< ";"
				<< "nb_deposits:"	<< _nbDeposits	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	t::_displayTimestamp();
	std::cout	<< "index:"		<< _accountIndex	<< ";"
				<< "p_amount:"	<< _amount 			<< ";";
	if (t::checkAmount() < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);  
	}
	std::cout	<< "withdrawal:" << withdrawal 		<< ";";
	this->_amount			-= withdrawal;
	this->_nbWithdrawals	+= 1;
	_totalAmount			-= withdrawal;
	_totalNbWithdrawals		+= 1;
	std::cout	<< "amount:"			<< _amount			<< ";"
				<< "nb_withdrawals:"	<< _nbWithdrawals	<< std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	t::_displayTimestamp();
	std::cout	<< "index:"			<< _accountIndex	<< ";"
				<< "amount:"		<< _amount 			<< ";"
				<< "deposits:"		<< _nbDeposits		<< ";"
				<< "withdrawals:"	<< _nbWithdrawals	<< std::endl;
}

void	Account::displayAccountsInfos(void)
{
	t::_displayTimestamp();
	std::cout	<< "accounts:"		<< _nbAccounts			<< ";"
				<< "total:"			<< _totalAmount			<< ";"
				<< "deposits:"		<< _totalNbDeposits		<< ";"
				<< "withdrawals:"	<< _totalNbWithdrawals	<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::cout << "[19920104_091532] ";
}
