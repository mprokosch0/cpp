
#include "../includes/Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);

	std::cout << "["
		<< 1900 + ltm->tm_year
		<< std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon
		<< std::setfill('0') << std::setw(2) << ltm->tm_mday
		<< "_"
		<< std::setfill('0') << std::setw(2) << ltm->tm_hour
		<< std::setfill('0') << std::setw(2) << ltm->tm_min
		<< std::setfill('0') << std::setw(2) << ltm->tm_sec
		<< "] ";
	return ;
}

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	static int i = 0;

	this->_nbAccounts = i + 1;
	this->_totalAmount += initial_deposit;
	this->_accountIndex = i;
	_displayTimestamp();
	std::cout 	<< "index:" << i++
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
	return ;
	return ;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";deposit:" << deposit
				<< ";amount:" << deposit + this->_amount
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	return ;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		std::cout 	<< ";withdrawal:refused"
					<< std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	std::cout 	<< ";withdrawal:" << withdrawal
				<< ";amount:" << this->_amount - withdrawal
				<< ";nb_withdrawal:" << this->_nbDeposits
				<< std::endl;
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	return true;
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}
