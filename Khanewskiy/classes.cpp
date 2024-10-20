#include "headers/classes.h"

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#ifndef STRING_H
#define STRING_H
#include <string>
#endif

#ifndef FSTREAM_H
#define FSTREAM_H
#include <fstream>
#endif

#ifndef CHECKCINERROR_H
#define CHECKCINERROR_H
#include "headers/checkCinError.h"
#endif

Pipe::Pipe() {
	isRepairing = false;
}

void Pipe::addPipe() {
	std::cout << "Enter name(mileage) of the pipe: ";
	getline(std::cin >> std::ws, name);

	while (true) {
		std::cout << "\nEnter pipe length (in meters): ";
		std::cin >> length;

		if (checkCinError()) {
			if (length <= 0) {
				std::cout << "ERROR. Pipe length can`t be less than 0 meters or be equal 0 meters\n";
			}
			else if (length > 50) {
				std::cout << "ERROR. Pipe length can`t be more than 50 meters\n";
			}
			else {
				break;
			}
		}
		
	}

	while (true) {
		std::cout << "\nEnter pipe diameter (in millimeters): ";
		std::cin >> diameter;

		if (checkCinError()) {
			if (diameter <= 0) {
				std::cout << "ERROR. Pipe diameter can`t be less than 0 millimeters or be equal 0 millimeters\n";
			}
			else if (diameter > 5000) {
				std::cout << "ERROR. Pipe diameter can`t be more than 5000 millimeters\n";
			}
			else {
				break;
			}
		}
	}

	while (true) {
		std::cout << "\nChoose pipe status (0 - in repairing, 1 - not in repairing): ";
		std::cin >> isRepairing;

		if (checkCinError()) {
			if (std::cin.good()) {
				break;
			}
		}
	}
}

void Pipe::editPipe() {
	while (true) {
		std::cout << "Enter new pipe status (0 - in repairing, 1 - not in repairing): ";
		std::cin >> isRepairing;

		if (checkCinError()) {
			if (std::cin.good()) {
				break;
			}
		}
	}
}

bool Pipe::savePipe(std::ofstream& out, bool pipeExist) {
	if (out.is_open()) {
		if (pipeExist)
			out << "1" << "\n" << name << "\n" << length << "\n" << diameter << "\n" << isRepairing << "\n";
		else
			out << "0\n";
		return true;
	}
	return false;
}

bool Pipe::loadPipe(std::ifstream& in) {
	int pipeCount;

	if (in.is_open()) {
		in >> pipeCount;
		for (int i = 0; i < pipeCount; i++) {
			getline(in >> std::ws, name);
			in >> length;
			in >> diameter;
			in >> isRepairing;
		}
		if (pipeCount)
			return true;
	}
	return false;
}

void Pipe::showPipes() {
	std::cout << "Information about pipes:\n\n"
		<< "Pipe name: " << name
		<< "\nPipe length: " << length << " meters"
		<< "\nPipe diameter: " << diameter << " millimeters"
		<< "\nPipe status: " << ((isRepairing) ? "not" : "") << " in repairing\n\n\n";
}


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

bool CompressorStation::saveCs(std::ofstream& out, bool csExist) {
	if (out.is_open()) {
		if (csExist)
			out << "1" << "\n" << name << "\n" << workshopNum << "\n" << activeWorkshopNum << "\n" << effectiveness << "\n";
		else
			out << "0";
		return true;
	}
	return false;
}

bool CompressorStation::loadCs(std::ifstream& in) {
	int csCount;

	if (in.is_open()) {
		in >> csCount;
		for (int i = 0; i < csCount; i++) {
			getline(in >> std::ws, name);
			in >> workshopNum;
			in >> activeWorkshopNum;
			in >> effectiveness;
		}
		if (csCount)
			return true;
	}
	return false;
}

void CompressorStation::showCss() {
	std::cout << "Information about compressor stations:\n\n"
	<< "Compressor station name: " << name
	<< "\nThe number of workshops: " << workshopNum
	<< "\nThe number of active workshops: " << activeWorkshopNum
	<< "\nThe compressor station effectiveness: " << effectiveness << "\n\n\n";
}