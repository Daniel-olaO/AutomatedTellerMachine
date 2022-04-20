#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "atm.h"
#include <string>

using namespace daniel;

Atm::Atm(){}
Atm::Atm(const char* name, double balance){
	if (name != nullptr && name[0] != '\0' && strlen(name) > 0){
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		m_balance = balance;
	}
}
Atm::Atm(const Atm& other){
	*this = other;
}
Atm& Atm::operator=(const Atm& other){
	if (this != &other){
		if (m_name != nullptr){
			delete[] m_name;
		}
		if (other.m_name != nullptr){
			m_name = new char[strlen(other.m_name) + 1];
			strcpy(m_name, other.m_name);
		}
		m_balance = other.m_balance;
	}
	return *this;
}
Atm::~Atm() {
	delete[] m_name;
	m_name = nullptr;
}
void Atm::run(){
	std::cout << "Press enter to continue..." << std::endl;
	std::cin.get();
	
	int choice = menu();
	while (choice != 6) {
		if(choice == 1){
			std::cout << "Current Balance: $" << getBalance() << std::endl;
		}
		else if(choice == 2){
			double amount{0}; 
			std::cout << "How much would you like to deposit: ";
			std::cin >> amount;
			deposit(amount);
		}
		else if(choice == 3){
			double amount{0};
			std::cout << "How much would you like to withdraw: ";
			std::cin >> amount;
			withdraw(amount);
		}
		else if(choice == 4){
			std::string name{};
			std::cout << "Enter the name of the person you would like to transfer to: ";
			std::cin >> name;
			
			Atm* recipent = new Atm(name.c_str());
			
			transfer(*recipent);
			
		}
		else if(choice == 5){
			std::string name;
		
			std::cout << "Enter the name of the account holder: ";
			getline(std::cin, name);
			setName(name.c_str());
		}
		choice = menu();
	}
	std::cout << "Thank you for using the ATM!" << std::endl;
}
void Atm::deposit(double amount){
	if (amount > 0){
		m_balance += amount;
	}
}
void Atm::withdraw(double amount){
	if (amount > 0){
		if(amount <= m_balance){
			m_balance -= amount;
			std::cout << "Withdrawal successful" << std::endl;
		}
		else {
			std::cout << "you don't have enough money" << std::endl;
		}
	}
}

int Atm::menu()const {
	int choice{0};
	bool valid{false};
	std::cout << "========================================" << std::endl;
	std::cout << "Welcome to the ATM of " << m_name << std::endl;
	std::cout << "========================================" << std::endl << std::endl;
	std::cout << "1. Check balance" << std::endl;
	std::cout << "2. Deposit" << std::endl;
	std::cout << "3. Withdraw" << std::endl;
	std::cout << "4. Transfer Fund" << std::endl;
	std::cout << "5. Edit name" << std::endl;
	std::cout << "6. Exit" << std::endl << std::endl;
	
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	while (!valid){
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
			std::cout << "Enter your choice: ";
			std::cin >> choice;
		}
		else if (choice < 1 || choice > 6){
			std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
			std::cout << "Enter your choice: ";
			std::cin >> choice;
		}
		else{
			valid = true;
		}
	}
	return choice;
}
void Atm::setName(const char* name){
	if (name != nullptr && name[0] != '\0' && strlen(name) > 0){
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}
}
void Atm::transfer(Atm& other){
	double amount{0};
	std::cout << "Enter the amount to transfer: ";
	std::cin >> amount;
	if (amount > 0){
		if (amount <= m_balance){
			m_balance -= amount;
			other.m_balance += amount;
			std::cout << "Transfer successful" << std::endl;
		}
		else {
			std::cout << "you don't have enough money" << std::endl;
		}
	}
}
const char* Atm::getName()const{
	return m_name;
}
double Atm::getBalance()const{
	return m_balance;
}
void Atm::setBalance(double amount) {
	m_balance = amount;
}