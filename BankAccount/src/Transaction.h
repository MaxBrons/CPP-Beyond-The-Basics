#pragma once
#include <string>

namespace BankAccount
{
	class Transaction
	{
	public:
		enum Type {
			None,
			Add,
			Remove
		};
	public:
		Transaction(const std::string& source, float amount, Type type, const std::string& date, float balance);
		~Transaction() = default;

		const std::string& GetSource() const { return m_Source; }
		float GetAmount() const { return m_Amount; }
		const std::string& GetDate() const { return m_Date; }
		float GetPreBalance() const { return m_PreBalance; }
		float GetPostBalance() const { return m_PostBalance; }
		Type GetType() const { return m_Type; }

		bool operator ==(const Transaction& right);
		bool operator !=(const Transaction& right);
	private:
		std::string m_Source;
		float m_Amount;
		std::string m_Date;
		float m_PreBalance;
		float m_PostBalance;
		Type m_Type;
	};
}
