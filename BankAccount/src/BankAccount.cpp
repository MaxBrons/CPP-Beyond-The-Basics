#include "BankAccount.h"
#include "Colour.h"

#include <iomanip>

namespace BankAccount
{
	// This is used to create a highlighted textblock for the root headers.
	const std::string BankAccount::CreateHeader(const std::string& content) const
	{
		return Colour::Background::Green + content + Colour::Default;
	}

	// This is used to create a highlighted textblock for the sub headers.
	const std::string BankAccount::CreateDetailsHeader(const std::string& content) const
	{
		return Colour::Background::Blue + content + Colour::Default;
	}
	
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
		os << bankAccount.CreateHeader("ACOUNT INFORMATION") << std::endl;
		os << "| Account owner: " << bankAccount.GetAccountHolder() << std::endl;
		os << "| Account balance: EUR " << bankAccount.GetBalance() << std::endl << std::endl;

		// Print every transaction from this bank account with all it's details to the console.
		os << bankAccount.CreateHeader("TRANSACTION HISTORY") << std::endl;

		for (size_t i = 0; i < bankAccount.GetTransactionHistory().size(); i++)
		{
			const Transaction& transaction = bankAccount.GetTransactionHistory()[i];
			os << bankAccount.CreateDetailsHeader("| TRANSACTION DETAILS") << std::endl;
			os << " | Source: " << transaction.GetSource() << std::endl;
			os << " | Amount: " << "EUR " << 
				(
					(transaction.GetType() == Transaction::Type::Add)
					? (Colour::Foreground::Green +"+") 
					: (Colour::Foreground::Red + "-")
				) 
				<< std::fixed << std::setprecision(2) << transaction.GetAmount() << Colour::Default << std::endl;
			os << " | Date:   " << transaction.GetDate() << std::endl << std::endl;
			os << " | Balance before transaction: " << "EUR " << transaction.GetPreBalance() << std::endl;
			os << " | Balance after transaction: " << "EUR " << transaction.GetPostBalance() << std::endl << std::endl;
		}
		return os;
	}
}