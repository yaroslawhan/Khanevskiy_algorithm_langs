#include "headers/auxiliaryFuncs.h"

#include <iostream>
#include <string>
#include <vector>

void clearCin() {
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "ERROR\n";
}

bool checkCinError() {
	if (std::cin.fail()) {
		clearCin();
		return false;
	}
	return true;
}

short int choosingAction(const std::vector<std::string>& strVector) {
	for (std::string str : strVector)
		std::cout << "\n" << str;
	unsigned short int action;
	std::cin >> action;
	if (checkCinError())
		return action;
	else
		return -1;
}

void showMenu() {
	std::cout << "Gas pipeline transport model \n\n";
	std::cout << "Menu: \n";
	std::cout << "1. Add a pipe \n";
	std::cout << "2. Add a compressor station \n";
	std::cout << "3. View all objects \n";
	std::cout << "4. Edit pipes \n";
	std::cout << "5. Edit compressor stations \n";
	std::cout << "6. Save \n";
	std::cout << "7. Open \n";
	std::cout << "0. Exit \n\n";
	std::cout << "Please select an action :";
}

bool checkElementPresenceInMassive(const int& elem, const std::vector<int> massive) {
	for (int i = 0; i < massive.size(); i++) {
		if (elem == massive[i]) return true;
	}
	return false;
}