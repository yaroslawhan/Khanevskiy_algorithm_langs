#include "headers/compressorStationClass.h"
#include "headers/auxiliaryFuncs.h"

#include <iostream>
#include <string>
#include <fstream>

void CompressorStation::addCs() {
	std::cout << "Enter name of the compressor station: ";
	getline(std::cin >> std::ws, name);

	while (true) {
		std::cout << "\nEnter the number of workshops: ";
		std::cin >> workshopNum;

		if (checkCinError()) {
			if (workshopNum <= 0) {
				std::cout << "ERROR. The number of workshops can`t be less than 0 or be equal 0\n";
			}
			else if (workshopNum > 100) {
				std::cout << "ERROR. The number of workshops can`t be more than 100\n";
			}
			else {
				break;
			}
		}
	}

	while (true) {
		std::cout << "\nEnter the number of active workshops: ";
		std::cin >> activeWorkshopNum;

		if (checkCinError()) {
			if (activeWorkshopNum < 0) {
				std::cout << "ERROR. The number of active workshops can`t be less than 0\n";
			}
			else if (activeWorkshopNum > 100) {
				std::cout << "ERROR. The number of active workshops can`t be more than 100\n";
			}
			else if (activeWorkshopNum > workshopNum) {
				std::cout << "ERROR. The number of active workshops can`t be more than the number of workshops\n";
			}
			else {
				break;
			}
		}
	}

	while (true) {
		std::cout << "\nEnter the compressor station effectiveness: ";
		std::cin >> effectiveness;

		if (checkCinError()) {
			if (std::cin.good()) {
				break;
			}
		}
	}
}

void CompressorStation::editCs() {
	while (true) {
		std::cout << "\nEnter new value of active workshops: ";
		std::cin >> activeWorkshopNum;

		if (checkCinError()) {
			if (activeWorkshopNum < 0) {
				std::cout << "ERROR. The number of active workshops can`t be less than 0\n";
			}
			else if (activeWorkshopNum > 100) {
				std::cout << "ERROR. The number of active workshops can`t be more than 100\n";
			}
			else if (activeWorkshopNum > workshopNum) {
				std::cout << "ERROR. The number of active workshops can`t be more than the number of workshops\n";
			}
			else {
				break;
			}
		}
	}
}

void CompressorStation::saveCs(std::ofstream& out) {
	if (out.is_open()) {
			out << name << "\n" << workshopNum << "\n" << activeWorkshopNum << "\n" << effectiveness << "\n";
	}
}

void CompressorStation::loadCs(std::ifstream& in) {

	if (in.is_open()) {
		getline(in >> std::ws, name);
		in >> workshopNum;
		in >> activeWorkshopNum;
		in >> effectiveness;
	}
}

void CompressorStation::showCs() {
	std::cout << "Compressor station name: " << name
		<< "\nThe number of workshops: " << workshopNum
		<< "\nThe number of active workshops: " << activeWorkshopNum
		<< "\nThe compressor station effectiveness: " << effectiveness << "\n\n\n";
}

std::string CompressorStation::get_name()
{
	return name;
}

float CompressorStation::get_WorkshopsPercentage() {
	return 100 * (1 - (float)activeWorkshopNum / (float)workshopNum); //(((workshopNum - activeWorkshopNum) / workshopNum) * 100)
}