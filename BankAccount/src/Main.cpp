#include "BankAccount.h"

#include <iostream>

using namespace BankAccount;

// A bank account is created and a couple of transactions are made to the bank account
// and then printed to the console.
int main() 
{
	auto bankaccount = ::BankAccount::BankAccount("John Doe");
	bankaccount += Transaction("Salary", 1000.00f, Transaction::Type::Add, "01/10/2002", bankaccount.GetBalance());
	bankaccount -= Transaction("Baker", 99.99f, Transaction::Type::Remove, "05/06/2003", bankaccount.GetBalance());
	bankaccount -= Transaction("Shopping Mall", 10.00f, Transaction::Type::Remove, "04/09/2004", bankaccount.GetBalance());
	bankaccount += Transaction("Return Shopping Mall", 1000.00f, Transaction::Type::Add, "06/10/2005", bankaccount.GetBalance());
	bankaccount -= Transaction("Electronic & Co", 430.00f, Transaction::Type::Remove, "16/11/2006", bankaccount.GetBalance());
	bankaccount += Transaction("Payment Friend", 50.00f, Transaction::Type::Add, "03/1/2007", bankaccount.GetBalance());
	bankaccount += Transaction("Payment Friend", 50.00f, Transaction::Type::Add, "30/10/2008", bankaccount.GetBalance());

	std::cout << bankaccount << std::endl;
	return 0;
}