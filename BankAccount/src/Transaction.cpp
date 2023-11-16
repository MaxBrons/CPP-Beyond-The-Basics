#include "Transaction.h"
#include "GUI.h"

#include <iomanip>

namespace BankAccount
{
	// Create a new transaction with all the necessary details.
	Transaction::Transaction(const std::string& source, float amount, Type type, const std::string& date, float balance)
		:m_Source(source), m_Amount(amount), m_Type(type), m_Date(date), m_PreBalance(balance)
	{
		if (type != Type::None)
			m_PostBalance = balance + (type == Type::Add ? amount : -amount);
	}

	// Compare all the internal details to check if the transactions are the same.
	bool Transaction::operator==(const Transaction& right)
	{
		return std::strcmp(m_Source.c_str(), right.m_Source.c_str()) == 0
			&& m_Amount == right.m_Amount
			&& std::strcmp(m_Date.c_str(), right.m_Date.c_str()) == 0
			&& m_PreBalance == right.m_PreBalance
			&& m_PostBalance == right.m_PostBalance;
	}

	// Inverse of the compare operator
	bool Transaction::operator!=(const Transaction& right)
	{
		return !(*this == right);
	}

	// This will print all the details of a transaction to the console,
	// such as the source, the amount added or removed, the date and 
	// the pre-/post-balance of the bank account.
	std::ostream& operator<<(std::ostream& os, const Transaction& transaction)
	{
		os << GUI::CreateHeader("| TRANSACTION DETAILS", Colour::Background::Blue) << std::endl;
		os << " | Source: " << transaction.GetSource() << std::endl;
		os << " | Amount: " << "EUR " <<
			(
				(transaction.GetType() == Transaction::Type::Add)
				? (Colour::Foreground::Green + "+")
				: (Colour::Foreground::Red + "-")
				)
			<< std::fixed << std::setprecision(2) << transaction.GetAmount() << Colour::Default << std::endl;
		os << " | Date:   " << transaction.GetDate() << std::endl << std::endl;
		os << " | Balance before transaction: " << "EUR " << transaction.GetPreBalance() << std::endl;
		os << " | Balance after transaction: " << "EUR " << transaction.GetPostBalance() << std::endl;
		return os;
	}
}
