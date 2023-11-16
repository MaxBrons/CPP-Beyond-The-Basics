#pragma once
#include "Transaction.h"

#include <vector>
#include <iostream>

namespace BankAccount 
{
	class BankAccount
	{
	public:
		BankAccount(const std::string& accountHolder)
			:m_AccountHolder(accountHolder)
		{
		}
		~BankAccount() = default;

		const std::string CreateHeader(const std::string& content) const;
		const std::string CreateDetailsHeader(const std::string& content) const;

		const std::string& GetAccountHolder() const { return m_AccountHolder; }
		const float GetBalance() const { return m_Balance; }
		const std::vector<Transaction>& GetTransactionHistory() const { return m_TransactionHistory; }

		void operator +=(const Transaction& right);
		void operator -=(const Transaction& right);
		friend std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount);
	private:
		std::string m_AccountHolder;
		float m_Balance = 0.00f;
		std::vector<Transaction> m_TransactionHistory;
	};
}