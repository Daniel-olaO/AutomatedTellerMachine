#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "atm.h"

using namespace daniel;

void greeting();

int main() {
	int pin{ 0 };
	greeting();
	
	std::cout << "insert card to begin" << std::endl;
	std::cout << "reading card..." << std::endl;
	std::cout << "Enter PIN: ";
	std::cin >> pin;
	
	if (pin >= 1000 && pin <= 9999){
		
		Atm* client1 = new Atm("John  Doe", 5000);
		client1->run();
		
	}
	else {
		std::cout << "Invalid PIN" << std::endl;
	}
	greeting();

	std::cout << "insert card to begin" << std::endl;
	std::cout << "reading card..." << std::endl;
	std::cout << "Enter PIN: ";
	std::cin >> pin;

	if (pin >= 1000 && pin <= 9999) {

		Atm* client2 = new Atm("Jane  Doe", 5000);
		client2->run();

	}
	else {
		std::cout << "Invalid PIN" << std::endl;
	}
	
	return 0;
}
void greeting() {
	std::time_t currentTime = std::time(NULL);
	std::tm* localTime = std::localtime(&currentTime);
	
	if(localTime->tm_hour < 12) {
		std::cout << "Good morning!\n";
	} else if(localTime->tm_hour < 18) {
		std::cout << "Good afternoon!\n";
	} else {
		std::cout << "Good evening!\n";
	}
}