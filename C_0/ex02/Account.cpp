#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
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

int  Account::checkAmount() const
{
    return this->_amount;
}
Account::Account(int init)
{
    Account::_nbAccounts++;
    this->_accountIndex =  this->getNbAccounts() - 1;
    this->_amount += init;
    Account::_totalAmount += init;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << " ; amount:" << this->_amount << " created"<< std::endl;
}
Account::Account()
{
    Account::_nbAccounts++;
    this->_accountIndex =  this->getNbAccounts() - 1;
}

void Account::makeDeposit(int c)
{
    int prev = this->checkAmount();
    Account::_totalNbDeposits++;
    Account::_totalAmount += c;
    this->_amount += c;
    this->_nbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << " ; p_amount:" << prev << " ; deposit:" << c << " ; amount:" << this->checkAmount();
    std::cout << " ; nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int c)
{
    int prev = this->checkAmount();
    if (prev <  c)
    {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << " ; p_amount:" << prev << " ; withdrawal:refused" << std::endl;
        return false;
    }
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= c;
    this->_amount -= c;
    this->_nbWithdrawals++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << " ; p_amount:" << prev << " ; withdrawal:" << c << " ; amount:" << this->checkAmount();
    std::cout << " ; nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

void Account::_displayTimestamp()
{
    std::time_t now = std::time(0);
    std::cout << now << " ";
}

void Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << " amount: " << this->checkAmount() << " deposits:" << this->_nbDeposits << "withdrawals: " << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "Accounts: " << Account::getNbAccounts() << " ; total: " << Account::getTotalAmount() << " ; deposits:" << Account::getNbDeposits() << " ; withdrawals: " << Account::getNbWithdrawals() << std::endl;
}

Account::~Account()
{
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << " ; amount:" << this->_amount << " closed" << std::endl;
}