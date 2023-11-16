#include "Transaction.h"

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
}
