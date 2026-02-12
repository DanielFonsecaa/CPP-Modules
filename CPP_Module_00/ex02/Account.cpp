# include "Account.hpp"
# include <iostream>
# include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit ) {
	_nbAccounts += 1;
	_totalAmount += initial_deposit;

	_accountIndex = _nbAccounts - 1;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
//wrong
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
//wrong
int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
//wrong
void Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}
//maybe
void	Account::makeDeposit(int deposit)
{
	_totalAmount += deposit;
	_nbDeposits ++;
	_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	_amount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}
//maybe
bool	Account::makeWithdrawal(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (deposit > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= deposit;
		_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		Account::_totalAmount -= deposit;
		std::cout << deposit << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
}

int Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t time_stamp = std::time(NULL);
	std::tm *const time_struct = std::localtime(&time_stamp);

	std::cout << "[" << time_struct->tm_year + 1900;
	if ((time_struct->tm_mon + 1) < 10)
		std::cout << "0";
	std::cout << time_struct->tm_mon + 1;
	if (time_struct->tm_mday < 10)
		std::cout << "0";
	std::cout << time_struct->tm_mday << "_";
	std::cout << time_struct->tm_hour << time_struct->tm_min;
	std::cout << time_struct->tm_sec << "] ";
}