#pragma once
#ifndef SDDS_ATM_H__
#define SDDS_ATM_H__
namespace daniel {
	class Atm {
		char* m_name{ nullptr };
		double m_balance{ 0.00 };

	public:
		Atm();
		Atm(const char* name, double balance = 0.00);
		Atm(const Atm& obj);
		Atm& operator=(const Atm& obj);
		virtual ~Atm();
		void run();
		int menu()const;
		void deposit(double amount);
		void withdraw(double amount);
		void transfer(Atm& obj);
		void setName(const char* name);
		void setBalance(double balance);
		const char* getName() const;
		double getBalance() const;
	};
}

#endif // !atm
