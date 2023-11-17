#include "BankAccount.h"

#include <Core.h>

#include <iomanip>

namespace BankAccount
{
	// Makes a transaction to the bank account and increases the total balance.
	void BankAccount::operator+=(const Transaction& right)
	{
		m_TransactionHistory.push_back(Transaction(right));
		m_Balance += right.GetAmount();
	}

	// Makes a transaction to the bank account and decreases the total balance.
	void BankAccount::operator-=(const Transaction& right)
	{
		m_TransactionHistory.push_back(Transaction(right));
		m_Balance -= right.GetAmount();
	}

	// The following information about the bank account will be printed:
	// 1. The account information such as the account owner and current balance,
	// 2. All the transaction that are made to this account with all the 
	//	  transaction details.
	std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount)
	{
		// Print the owner and the current balance to the console.
		os << GUI::CreateHeader("ACOUNT INFORMATION", Colour::Background::Green) << std::endl;
		os << "| Account owner: " << bankAccount.GetAccountHolder() << std::endl;
		os << "| Account balance: EUR " << bankAccount.GetBalance() << std::endl << std::endl;

		// Print every transaction from this bank account with all it's details to the console.
		os << GUI::CreateHeader("TRANSACTION HISTORY", Colour::Background::Green) << std::endl;

		const auto& history = bankAccount.GetTransactionHistory();
		for (size_t i = 0; i < history.size(); i++)
			os << history[i] << std::endl;

		return os;
	}
}