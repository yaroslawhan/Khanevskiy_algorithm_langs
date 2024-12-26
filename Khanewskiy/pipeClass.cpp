#include "headers/pipeClass.h"
#include "headers/auxiliaryFuncs.h"

#include <iostream>
#include <string>
#include <fstream>

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

void Pipe::savePipe(std::ofstream& out) {
	if (out.is_open()) {
		out << name << "\n" << length << "\n" << diameter << "\n" << isRepairing << "\n";
	}
}

void Pipe::loadPipe(std::ifstream& in) {
	if (in.is_open()) {
		getline(in >> std::ws, name);
		in >> length;
		in >> diameter;
		in >> isRepairing;
	}
}

void Pipe::showPipe() {
	std::cout << "Pipe name: " << name
		<< "\nPipe length: " << length << " meters"
		<< "\nPipe diameter: " << diameter << " millimeters"
		<< "\nPipe status: " << ((isRepairing) ? "not " : "") << "in repairing\n\n\n";
}

std::string Pipe::get_name()
{
	return name;
}

bool Pipe::get_state() {
	return isRepairing;
}

bool Pipe::operator==(const Pipe& other) const {
	return name == other.name && diameter == other.diameter && length == other.length && isRepairing == other.isRepairing;
}